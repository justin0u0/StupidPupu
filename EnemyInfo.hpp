#ifndef ENEMYINFO_HPP
#define ENEMYINFO_HPP

#include <string>

struct EnemyInfo {
	std::string type;
	std::string img;
	int maximum_hp;
	int damage;
	float speed;
	float detect_radius;
	float attack_cooldown;
	explicit EnemyInfo(std::string type, std::string img, int maximum_hp
		, int damage, float speed, float detect_radius, float attack_cooldown, int universality);
	EnemyInfo(const EnemyInfo&) = default;
	EnemyInfo& operator=(const EnemyInfo&) = default;
};
#endif

