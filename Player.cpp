#include <cmath>
#include "Player.hpp"
#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Collider.hpp"

Player::Player(std::string img, float x, float y)
	: Sprite(img, x, y, 50, 50), real_position(Point(x, y)) {
	health = 50;
	maximum_health = 50;
	protect_cooldown = 3.0;
	tint_flag = false;
	tint_cooldown = 0;
}
void Player::OnMouseDown(int button, int mx, int my) {
}
void Player::OnMouseMove(int mx, int my) {
}
void Player::Draw() const {
	Sprite::Draw();
	tool->Draw();
}
void Player::Update(float deltaTime) {
	protect_cooldown -= deltaTime;
	tint_cooldown -= deltaTime;
	// player tint
	if (protect_cooldown > 0) {
		tint = (tint_flag ? al_map_rgba(255, 0, 0, 100) : al_map_rgba(255, 255, 255, 100));
		if (tint_cooldown < 0) {
			tint_flag ^= 1;
			tint_cooldown = 0.5;
		}
	} else {
		tint = al_map_rgba(255, 255, 255, 255);
	}
	GameEngine& game = GameEngine::GetInstance();
	// player direction
	if (game.GetMousePosition().x < position.x)
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else
		flag = 0;
	// player velocity
	velocity = GetVelocity();
	// player collide with resource
	PlayScene* playscene = dynamic_cast<PlayScene *>(game.GetActiveScene());
	Land* land = playscene->GetPlayerLand();
	Point next_position = real_position + velocity * deltaTime;
	for (auto& resource : land->resources) {
		if (Collider::CircleIntersect(Point(next_position.x, real_position.y), hitbox_radius, resource->real_position, resource->hitbox_radius))
			next_position.x = real_position.x;
		if (Collider::CircleIntersect(Point(real_position.x, next_position.y), hitbox_radius, resource->real_position, resource->hitbox_radius))
			next_position.y = real_position.y;
	}
	if (Collider::PointInRectangle(next_position, land->LeftUpCorner(), land->RightDownCorner())) {
		next_position.x = std::max(next_position.x, land->LeftUpCorner().x + size.x / 2);
		next_position.x = std::min(next_position.x, land->RightDownCorner().x - size.x / 2);
		next_position.y = std::max(next_position.y, land->LeftUpCorner().y + size.y / 2);
		next_position.y = std::min(next_position.y, land->RightDownCorner().y - size.y / 2);
	}
	playscene->pivot += (next_position - real_position);
	real_position = next_position;
	position = playscene->RepositionWithPivot(real_position);
	// get attacked
	for (auto& enemy : land->enemies) {
		if (protect_cooldown < 0 && Collider::CircleIntersect(position, hitbox_radius, enemy->position, enemy->hitbox_radius)) {
			Log(Debug) << "Player get attack.";
			protect_cooldown = 2.0;
			health -= enemy->damage;
		}
	}
	// tool update
	if (game.IsMouseDown() && tool->cooldown <= 0) {
		Point mouse = game.GetMousePosition();
		PlayScene* playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
		Land* land = playscene->GetPlayerLand();
		tool->PlayAnimation();
		for (auto resource : land->resources) {
			if (Distance(position, Point(mouse.x, mouse.y)) < (hitbox_radius + resource->hitbox_radius) * 2
				&& Collider::PointInCircle(Point(mouse.x, mouse.y), resource->position, resource->hitbox_radius)) {
				Log(Verbose) << "Player click resource at: (" << mouse.x << ',' << mouse.y << ')';
				resource->health -= tool->resource_damage;
			}
		}
		for (auto enemy : land->enemies) {
			if (Distance(position, Point(mouse.x, mouse.y)) < (hitbox_radius + enemy->hitbox_radius) * 2
				&& Collider::PointInCircle(Point(mouse.x, mouse.y), enemy->position, enemy->hitbox_radius)) {
				Log(Verbose) << "Player click enemy at: (" << mouse.x << ',' << mouse.y << ')';
				enemy->health -= tool->enemy_damage;
			}
		}
	}
	tool->Update(deltaTime);
}
Point Player::GetVelocity() const {
	GameEngine& game = GameEngine::GetInstance();
	Point v(0, 0);
	if (game.IsLeft())
		v.x = -60;
	else if (game.IsRight())
		v.x = 60;
	if (game.IsUp())
		v.y = -60;
	else if (game.IsDown())
		v.y = 60;
	if (v.x > 0 && v.y > 0) {
		v.x /= sqrt(2.0);
		v.y /= sqrt(2.0);
	}
	return v;
}
void Player::ChangeTool(Tool* tool) {
	this->tool = tool;
}

