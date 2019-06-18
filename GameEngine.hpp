#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>

class GameEngine {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH;

	ALLEGRO_DISPLAY *display = nullptr;

	// Initialize allegro 5, create window
	void initAllegro5();
public:
	// Constructor
	GameEngine(int fps, int screenW, int screenH);
	// Start game loop
	void start();
};
#endif
