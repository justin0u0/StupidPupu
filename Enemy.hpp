#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Sprite.hpp"

class Enemy : public Sprite {
	float speed;
	float detect_radius;
	float attack_cooldown;
	float change_direction_cooldown = 0.0;
public:
	int health;
	int damage;
	explicit Enemy(std::string, float x, float y, float w, float h
		, int health, int damage, float speed, float detect_radius, float attack_cooldown);
	void Update(float deltaTime) override;
};
#endif

