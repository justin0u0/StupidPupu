#ifndef TOOL_HPP
#define TOOL_HPP

#include "Sprite.hpp"
#include "Item.hpp"

class Tool : public Sprite, public Item {
public:
	int durability;
	int resource_damage;
	int enemy_damage;
	float attack_speed;
	float cooldown;
	explicit Tool(std::string name, std::string img, float w, float h
		, int durability, int resource_damage, int enemy_damage, float attack_speed);
	void PlayAnimation();
	void Update(float deltaTime) override;
};
#endif

