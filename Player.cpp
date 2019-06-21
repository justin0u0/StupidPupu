#include "Player.hpp"
#include "GameEngine.hpp"

Player::Player(std::string img, float x, float y) : Sprite(img, x, y, 50, 50) {
}
void Player::OnMouseDown(int button, int mx, int my) {
}
void Player::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	if (game.IsLeft())
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else if (game.IsRight())
		flag = 0;
}

