#ifndef ENEMYINFO_HPP
#define ENEMYINFO_HPP

#include <string>
#include "Point.hpp"

struct EnemyInfo {
	std::string type;
	std::string img;
	Point size;
	int maximum_hp;
	int damage;
	float speed;
	float detect_radius;
	float attack_cooldown;
	int universality;
	explicit EnemyInfo(std::string type, std::string img, float w, float h, int maximum_hp
		, int damage, float speed, float detect_radius, float attack_cooldown, int universality);
	EnemyInfo(const EnemyInfo&) = default;
	EnemyInfo& operator=(const EnemyInfo&) = default;
};
#endif

