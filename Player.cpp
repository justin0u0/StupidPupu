#include <cmath>
#include "Player.hpp"
#include "GameEngine.hpp"
#include "PlayScene.hpp"

Player::Player(std::string img, float x, float y)
	: Sprite(img, x, y, 50, 50), real_position(Point(x, y)) {
}
void Player::OnMouseDown(int button, int mx, int my) {
}
void Player::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	if (game.IsLeft())
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else if (game.IsRight())
		flag = 0;
	velocity = GetVelocity();
	real_position += velocity * deltaTime;
	position = real_position;
	dynamic_cast<PlayScene *>(game.GetActiveScene())->RepositionWithPivot(position);
}
Point Player::GetVelocity() const {
	GameEngine& game = GameEngine::GetInstance();
	Point v(0, 0);
	if (game.IsLeft())
		v.x = -60;
	else if (game.IsRight())
		v.x = 60;
	if (game.IsUp())
		v.y = -60;
	else if (game.IsDown())
		v.y = 60;
	if (v.x > 0 && v.y > 0) {
		v.x /= sqrt(2.0);
		v.y /= sqrt(2.0);
	}
	return v;
}

