#include "GameEngine.hpp"
#include "Log.hpp"
#include "SelectScene.hpp"

int main() {
	GameEngine &game = GameEngine::GetInstance();
	game.AddNewScene("start", nullptr);
	game.AddNewScene("select", new SelectScene());
	game.Start(60, 1536, 960, "StupidPupu", "select");
	return 0;
}

