#include <allegro5/allegro.h>
#include "Enemy.hpp"
#include "Random.hpp"
#include "GameEngine.hpp"

Enemy::Enemy(std::string img, float x, float y, float w, float h
	, int health, int damage, float speed, float detect_radius, float attack_cooldown)
	: Sprite(img, x, y, w, h), health(health), damage(damage), speed(speed)
	, detect_radius(detect_radius), attack_cooldown(attack_cooldown) {
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
//		velocity.x = -60;
//	else if (game.IsRight())
//		velocity.x += 60;
//	if (game.IsUp())
//		velocity.y -= 60;
//	else if (game.IsDown())
//		velocity.y += 60;
	if (velocity.x > 0)
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else
		flag = 0;
	Sprite::Update(deltaTime);
}

