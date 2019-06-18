#include "GameEngine.hpp"

GameEngine::GameEngine(int fps, int screenW, int screenH): fps(fps), screenW(screenW), screenH(screenH) {
}

void GameEngine::initAllegro5() {
	if (!al_init()) {
		// error handler
	}

	display = al_create_display(screenW, screenH);
	if (!display) {
	}

	al_clear_to_color(al_map_rgb(0,0,0));
   
   al_flip_display();

   al_rest(10.0);

   al_destroy_display(display);
}

void GameEngine::start() {
	initAllegro5();
}
