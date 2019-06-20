#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
//#incldue <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <chrono>

#include "GameEngine.hpp"
#include "Log.hpp"
#include "IScene.hpp"
#include "Image.hpp"

/* testing
float x, y;
bool key_state[ALLEGRO_KEY_MAX];
Image* rabbit;
*/

void GameEngine::InitAllegro5() {
	// Initialize allegro
	if (!al_init())
		Log(Error) << "failed to initialize allegro";
	// Initialize addon
	if (!al_init_primitives_addon())
		Log(Error) << "failed to initialize primitives addon";
	if (!al_init_image_addon())
		Log(Error) << "failed to initialize image addon";
	if (!al_init_font_addon())
		Log(Error) << "failed to initialize font addon";
	if (!al_init_ttf_addon())
		Log(Error) << "failed to initialize ttf addon";
	
	if (!al_install_keyboard())
		Log(Error) << "failed to install keyboard";
	if (!al_install_mouse())
		Log(Error) << "failed to install mouse";

	/* testing
	x = 50.0;
	y = 50.0;
	rabbit = new Image("rabbit.png", x, y);
	*/
	
	// set game display
	display = al_create_display(screenW, screenH);
	if (!display) {
		Log(Error) << "failed to set game display";
	}

	al_set_window_title(display, title);

	// setup update timer
	update_timer = al_create_timer(1.0f / fps);
	if (!update_timer) {
		Log(Error) << "failed to set update timer";
	}

	// setup event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		Log(Error) << "failed to set event queue";
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
				Log(Info) << "Windows close button clicked";
				done = true;
				break;
			case ALLEGRO_EVENT_TIMER:
				// Event for redrawing the display.
				if (event.timer.source == update_timer)
					// The redraw timer has ticked.
					redraws++;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				Log(Verbose) << "Key with keycode " << event.keyboard.keycode << " down";
				active_scene->OnKeyDown(event.keyboard.keycode);
				// key_state[event.keyboard.keycode] = true;
				break;
			case ALLEGRO_EVENT_KEY_UP:
				Log(Verbose) << "Key with keycode " << event.keyboard.keycode << " up";
				active_scene->OnKeyUp(event.keyboard.keycode);
				// key_state[event.keyboard.keycode] = false;
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				Log(Verbose) << "Mouse button " << event.mouse.button << " down at (" << event.mouse.x << "," << event.mouse.y << ")";
				active_scene->OnMouseDown(event.mouse.button, event.mouse.x, event.mouse.y);
				break;
			case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
				Log(Verbose) << "Mouse button " << event.mouse.button << " up at (" << event.mouse.x << "," << event.mouse.y << ")";
				active_scene->OnMouseUp(event.mouse.button, event.mouse.x, event.mouse.y);
				break;
			case ALLEGRO_EVENT_MOUSE_AXES:
				if (event.mouse.dx != 0 || event.mouse.dy != 0) {
					Log(Verbose) << "Mouse move to (" << event.mouse.x << "," << event.mouse.y << ")";
					active_scene->OnMouseMove(event.mouse.x, event.mouse.y);
				} else if (event.mouse.dz != 0) {
					Log(Verbose) << "Mouse scroll at (" << event.mouse.x << "," << event.mouse.y << ") with delta " << event.mouse.dz;
					active_scene->OnMouseScroll(event.mouse.x, event.mouse.y, event.mouse.dz);
				}
				break;
			case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
				Log(Verbose) << "Mouse leave display.";
				ALLEGRO_MOUSE_STATE state;
				al_get_mouse_state(&state);
				active_scene->OnMouseMove(-1, -1);
				break;
			case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
				Log(Verbose) << "Mouse enter display.";
				break;
			default:
				break;
		}
		// Redraw the scene.
		if (redraws > 0 && al_is_event_queue_empty(event_queue)) {
			if (redraws > 1)
				Log(Verbose) << redraws - 1 << " frame(s) dropped";
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
void GameEngine::ChangeScene(const std::string& name) {
	if (!scenes.count(name))
		Log(Error) << "Cannot change to unknown " << name << " scene";
	active_scene->Terminate();
	active_scene = scenes[name];
	active_scene->Initialize();
	Log(Info) << "Change to " << name << " scene";
}
void GameEngine::Draw() {
	/* testing
	al_clear_to_color(al_map_rgb(0, 0, 0));
	rabbit->Draw();
	al_draw_filled_rectangle(x, y, x + 800, y + 800, al_map_rgb(255, 150, 170));
	al_flip_display();
	*/
	active_scene->Draw();
	al_flip_display();
}
void GameEngine::Update(float deltaTime) {
	if (!next_scene.empty()) {
		ChangeScene(next_scene);
		next_scene = "";
	}
	active_scene->Update(deltaTime);
	/* testing
	if (key_state[ALLEGRO_KEY_UP])
		rabbit->position.y -= 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_DOWN])
		rabbit->position.y += 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_RIGHT])
		rabbit->position.x += 30 * deltaTime;
	if (key_state[ALLEGRO_KEY_LEFT])
		rabbit->position.x -= 30 * deltaTime;
	*/
}
void GameEngine::Destroy() {
	al_destroy_timer(update_timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);
}
void GameEngine::Start(int fps, int screenW, int screenH, const char *title, const std::string& first_scene) {
	Log(Info) << "Initializeing ...";
	this->fps = fps;
	this->screenW = screenW;
	this->screenH = screenH;
	this->title = title;
	if (!scenes.count(first_scene))
		Log(Error) << "Scene: " << first_scene << " has not been added yet";
	active_scene = scenes[first_scene];
	Log(Info) << "Allegro Initializing ...";
	InitAllegro5();
	Log(Info) << "Allegro Initialized.";
	Log(Info) << "Game Initializing ...";
	active_scene->Initialize();
	Log(Info) << "Game Initialized.";
	Draw();
	Log(Info) << "Start Event Loop.";
	StartEventLoop();
	Log(Info) << "Game Terminating ...";
	active_scene->Terminate();
	Destroy();
	Log(Info) << "End";
}
void GameEngine::AddNewScene(const std::string& name, IScene* scene) {
	if (scenes.count(name))
		Log(Error) << "Cannot add scene with the same name";
	scenes[name] = scene;
}
void GameEngine::SetNextScene(const std::string& name) {
	next_scene = name;
}
int GameEngine::GetScreenWidth() const {
	return screenW;
}
int GameEngine::GetScreenHeight() const {
	return screenH;
}
Point GameEngine::GetMousePosition() const {
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	return Point(state.x, state.y);
}
GameEngine& GameEngine::GetInstance() {
	static GameEngine instance;
	return instance;
}

