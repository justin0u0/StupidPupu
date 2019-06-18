#include <allegro5/allegro_primitives.h>

#include "GameEngine.hpp"
#include "Allegro5Exception.hpp"

GameEngine::GameEngine(int fps, int screenW, int screenH, const char *title): fps(fps), screenW(screenW), screenH(screenH) {
}

void GameEngine::InitAllegro5() {
	// Initialize allegro
	if (!al_init())
		throw Allegro5Exception("failed to initialize allegro");
	// Initialize addon
	if (!al_init_primitives_addon())
		throw Allegro5Exception("failed to initialize primitives addon");
	if (!al_install_keyboard())
		throw Allegro5Exception("failed to install keyboard");
	if (!al_install_mouse())
		throw Allegro5Exception("failed to install mouse");

	// set game display
	display = al_create_display(screenW, screenH);
	if (!display) {
		throw Allegro5Exception("failed to set game display");
	}

	al_set_window_title(display, title);

	// setup update timer
	update_timer = al_create_timer(1.0f / fps);
	if (!update_timer) {
		throw Allegro5Exception("failed to set update timer");
	}

	// setup event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		throw Allegro5Exception("failed to set event queue");
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(update_timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(update_timer);
}

void GameEngine::Start() {
	InitAllegro5();
	al_clear_to_color(al_map_rgb(0,0,0));

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);
}

