#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>

class GameEngine final {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH; //reserveSamples{}
	// game title
	const char *title;
	// allegro resource
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_TIMER *update_timer = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	// active scene & next scene & scenes
	unordered_map<string, 

	// Initialize allegro 5, create window
	void InitAllegro5();
	void StartEventLoop();
	void Draw();
	void Update(float deltaTime);
	void Destroy();
public:
	// Constructor
	GameEngine(int fps, int screenW, int screenH, const char *title);
	// Start game loop
	void Start();
	// Screen width
	int GetScreenWidth();
	// Screen height
	int GetScreenHeight();
};
#endif

