#include "Resource.hpp"
#include "GameEngine.hpp"
#include "Resource.hpp"

Resource::Resource(std::string img, float x, float y, int health)
	: Sprite(img, x, y, 50, 50, 0.5, 0.5, 0, 0, 0, 255, 0, 0, 100, 0), health(health) {
}
void Resource::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	if (game.IsLeft())
		velocity.x = 60;
	else if (game.IsRight())
		velocity.x = -60;
	else
		velocity.x = 0;
	if (game.IsUp())
		velocity.y = 60;
	else if (game.IsDown())
		velocity.y = -60;
	else
		velocity.y = 0;
	Sprite::Update(deltaTime);
}

