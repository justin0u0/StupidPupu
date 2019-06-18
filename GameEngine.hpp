#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>

class GameEngine {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH;
	// game title
	const char *title; 
	
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_TIMER *update_timer = nullptr;

	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

	// Initialize allegro 5, create window
	void InitAllegro5();

	void startEventLoop();
public:
	// Constructor
	GameEngine(int fps, int screenW, int screenH, const char *title="Stupid Pupu");
	// Start game loop
	void Start();
};
#endif

