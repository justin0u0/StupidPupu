#include "GameEngine.hpp"
#include "SelectScene.hpp"
#include "PlayScene.hpp"

int main() {
	GameEngine &game = GameEngine::GetInstance();
	game.AddNewScene("start", nullptr);
	game.AddNewScene("select", new SelectScene());
	game.AddNewScene("play", new PlayScene());
	game.Start(60, 1536, 960, "StupidPupu", "select");
	return 0;
}

