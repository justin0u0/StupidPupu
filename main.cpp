#include "GameEngine.hpp"
#include <iostream>
#include "Log.hpp"

int main() {
	GameEngine &game = GameEngine::GetInstance();
	game.AddNewScene("start", nullptr);
	game.Start(60, 1536, 960, "StupidPupu", "start");
	return 0;
}

