#include <allegro5/allegro_primitives.h>
#include <chrono>
#include "GameEngine.hpp"
#include "Log.hpp"
#include "IScene.hpp"

float x, y;
bool key_state[ALLEGRO_KEY_MAX];

void GameEngine::InitAllegro5() {
	x = screenW / 2.0;
	y = screenH / 2.0;
	// Initialize allegro
	if (!al_init())
		Log(Error) << ("failed to initialize allegro");
	// Initialize addon
	if (!al_init_primitives_addon())
		Log(Error) << ("failed to initialize primitives addon");
//	if (!al_init_ttf_addon())
//		throw Allegro5Exception("failed to initialize ttf add-on");
//	if (!al_init_image_addon())
//		throw Allegro5Exception("failed to initialize image add-on");
//	if (!al_inatall_audio())
//		throw Allegro5Exception("failed to install audio add-on");
//	if (!al_init_acodec_addon())
//		throw Allegro5Exception("failed to initialize audio codec add-on");
//	if (!al_reserve_samples(reserveSamples))
//		throw Allegro5Exception("failed to reserve samples");

	if (!al_install_keyboard())
		Log(Error) << ("failed to install keyboard");
	if (!al_install_mouse())
		Log(Error) << ("failed to install mouse");

	// set game display
	display = al_create_display(screenW, screenH);
	if (!display) {
		Log(Error) << ("failed to set game display");
	}

	al_set_window_title(display, title);

	// setup update timer
	update_timer = al_create_timer(1.0f / fps);
	if (!update_timer) {
		Log(Error) << ("failed to set update timer");
	}

	// setup event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		Log(Error) << ("failed to set event queue");
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(update_timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(update_timer);
}
void GameEngine::StartEventLoop() {
	bool done = false;
	int redraws = 0;
	ALLEGRO_EVENT event;
	auto timestamp = std::chrono::steady_clock::now();
	while (!done) {
		al_wait_for_event(event_queue, &event);
		switch(event.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				done = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				// Event for redrawing the display.
				if (event.timer.source == update_timer)
					// The redraw timer has ticked.
					redraws++;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				key_state[event.keyboard.keycode] = true;
//				switch(event.keyboard.keycode) {
//		        case ALLEGRO_KEY_UP:
//           			y -= 10;
//                  	break;
//             	case ALLEGRO_KEY_DOWN:
//                    y += 10;
//                    break;
//               	case ALLEGRO_KEY_LEFT:
//                    x -= 10;
//                    break;
//               	case ALLEGRO_KEY_RIGHT:
//                   x += 10;
//                   break;
				break;
			case ALLEGRO_EVENT_KEY_UP:
				key_state[event.keyboard.keycode] = false;
				break;
		}
		// Redraw the scene.
		if (redraws > 0 && al_is_event_queue_empty(event_queue)) {
			if (redraws > 1)
				Log(Info) << redraws - 1 << " frame(s) dropped";
			// Calculate the timeElapsed and update the timestamp.
			auto nextTimestamp = std::chrono::steady_clock::now();
			std::chrono::duration<float> timeElapsed = nextTimestamp - timestamp;
			timestamp = nextTimestamp;
			// Update and draw the next frame.
			Update(timeElapsed.count());
			Draw();
			redraws = 0;
		}
	}
}
void GameEngine::Draw() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(x, y, x + 50, y + 50, al_map_rgb(255, 150, 170));
	al_flip_display();
}
void GameEngine::Update(float deltaTime) {
	if (key_state[ALLEGRO_KEY_UP])
		y -= 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_DOWN])
		y += 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_RIGHT])
		x += 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_LEFT])
		x -= 30 * deltaTime;
}
void GameEngine::Destroy() {
	al_destroy_timer(update_timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}
void GameEngine::Start(int fps, int screenW, int screenH, const char *title, const char *first_scene) {
	Log(Info) << "Game Initializeing ...";
	this->fps = fps;
	this->screenW = screenW;
	this->screenH = screenH;
	this->title = title;
	if (!scenes.count(first_scene))
		Log(Error) << "Scene: " << first_scene << " has not been added yet";
	active_scene = scenes[first_scene];
	InitAllegro5();
	Log(Info) << "Game Initialized";
	StartEventLoop();
	Destroy();
}
void GameEngine::AddNewScene(const std::string name, IScene* scene) {
	if (scenes.count(name))
		Log(Error) << "Cannot add scene with the same name";
	scenes[name] = scene;
}
int GameEngine::GetScreenWidth() const {
	return screenW;
}
int GameEngine::GetScreenHeight() const {
	return screenH;
}
GameEngine& GameEngine::GetInstance() {
	static GameEngine instance;
	return instance;
}

