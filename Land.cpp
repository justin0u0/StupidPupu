#include "Land.hpp"
#include "GameEngine.hpp"

Land::Land(std::string img, int x, int y)
	: Sprite(img, x, y, 800, 820) {
}
void Land::Update(float deltaTime) {
	GameEngine& game = GameEngine::GetInstance();
	// Since Player is pivot at (0, 0), so lands need to move opposite side
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

