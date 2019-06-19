#include "GameEngine.hpp"
#include <iostream>
#include "LOG.hpp"

int main() {
	GameEngine game(60, 1024, 800, "Stupid Pupu");
	game.Start();
}

