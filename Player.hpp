#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sprite.hpp"
#include "IControl.hpp"

class Player : public Sprite, public IControl {
private:
public:
	int hp;
	explicit Player(std::string img, float x, float y);
	void OnMouseDown(int button, int mx, int my);
	void Update(float deltaTime) override;
};
#endif

