#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>
#include <string>

class GameEngine {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH;
	// game title
	string title;

	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_TIMER *update_timer = nullptr;

	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;

	// Initialize allegro 5, create window
	void InitAllegro5();
public:
	// Constructor
	GameEngine(int fps, int screenW, int screenH, string title);
	// Start game loop
	void Start();
};
#endif

