#include <cmath>
#include "Player.hpp"
#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Collider.hpp"

Player::Player(std::string img, float x, float y)
	: Sprite(img, x, y, 50, 50), real_position(Point(x, y)) {
}
void Player::OnMouseDown(int button, int mx, int my) {
}
void Player::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	if (game.IsLeft())
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else if (game.IsRight())
		flag = 0;
	velocity = GetVelocity();
	PlayScene *playscene = dynamic_cast<PlayScene *>(game.GetActiveScene());
	std::vector<Land *>& lands = playscene->lands;
	Point next_position = real_position + velocity * deltaTime;
	for (auto& land : lands) {
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
	}
	playscene->pivot += (next_position - real_position);
	real_position = next_position;
	position = playscene->RepositionWithPivot(real_position);
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

