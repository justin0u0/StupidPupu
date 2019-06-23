#include "EnemyInfo.hpp"

EnemyInfo::EnemyInfo(std::string type, std::string img, float w, float h
	, int maximum_hp, int damage, float speed, float detect_radius, float attack_cooldown, int universality)
	: type(type), img(img), size(Point(w, h)), maximum_hp(maximum_hp), damage(damage), speed(speed)
	, detect_radius(detect_radius), attack_cooldown(attack_cooldown), universality(universality) {
}

