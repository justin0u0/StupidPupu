#include <allegro5/allegro.h>
#include "Enemy.hpp"
#include "Random.hpp"
#include "GameEngine.hpp"
#include "PlayScene.hpp"
#include "Collider.hpp"

Enemy::Enemy(std::string img, float x, float y, float w, float h
	, int health, int damage, float speed, float detect_radius, float attack_cooldown)
	: Sprite(img, x, y, w, h), real_position(Point(x, y)), health(health), damage(damage)
	, speed(speed), detect_radius(detect_radius), attack_cooldown(attack_cooldown) {
}
void Enemy::Update(float deltaTime) {
	change_direction_cooldown -= deltaTime;
	if (change_direction_cooldown < 0) {
		change_direction_cooldown = Random::GetRandom().Float(3, 5);
		velocity.x = Random::GetRandom().Float(-1, 1);
		velocity.y = sqrt(1 - velocity.x * velocity.x);
		if (Random::GetRandom().Integer(0, 1))
			velocity.y *= -1;
		velocity *= speed;
	}
	if (velocity.x > 0)
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else
		flag = 0;
	Point next_position = real_position + velocity * deltaTime;
	PlayScene *playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	std::vector<Land *>& lands = playscene->lands;
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
	real_position = next_position;
	position = playscene->RepositionWithPivot(real_position);
}

