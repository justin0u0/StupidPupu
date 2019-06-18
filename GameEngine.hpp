#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>

class GameEngine {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH;

	ALLEGRO_DISPLAY *display = nullptr;

	// Constructor
	GameEngine(int fps, int screenW, int screenH) {}
	// Initialize allegro 5, create window
	void initAllegro5() {}
public:
	// Start game loop
	void start() {}
}
#endif
