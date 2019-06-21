#include "GameEngine.hpp"
#include "SelectScene.hpp"
#include "PlayScene.hpp"
#include "StartScene.hpp"

int main() {
	GameEngine &game = GameEngine::GetInstance();
	game.AddNewScene("start", new StartScene());
	game.AddNewScene("select", new SelectScene());
	game.AddNewScene("play", new PlayScene());
	game.Start(60, 1536, 960, 15, "StupidPupu", "start");
	return 0;
}

