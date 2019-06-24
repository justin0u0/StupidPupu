#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sprite.hpp"
#include "IControl.hpp"
#include "Point.hpp"
#include "Tool.hpp"

class Player : public Sprite, public IControl {
private:
	float protect_cooldown;
	bool tint_flag;
	float tint_cooldown;
public:
	int health;
	int maximum_health;
	Point real_position;
	Tool* tool;
	explicit Player(std::string img, float x, float y);
	void OnMouseDown(int button, int mx, int my);
	void OnMouseMove(int mx, int my);
	void Draw() const override;
	void Update(float deltaTime) override;
	Point GetVelocity() const;
	void ChangeTool(Tool* tool);
};
#endif

