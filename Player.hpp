#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sprite.hpp"
#include "IControl.hpp"
#include "Point.hpp"

class Player : public Sprite, public IControl {
private:
public:
	int hp;
	Point real_position;
	explicit Player(std::string img, float x, float y);
	void OnMouseDown(int button, int mx, int my);
	void Update(float deltaTime) override;
	Point GetVelocity() const;
};
#endif

