#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>
#include <cstring>
#include <unordered_map>
#include "IScene.hpp"
 
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
	// scenes
	std::unordered_map<std::string, IScene *> scenes;
	// active scene
	IScene *active_scene;
	// next scene
	std::string next_scene;

	// Initialize allegro 5, create window
	void InitAllegro5();
	void StartEventLoop();
	void Draw();
	void Update(float deltaTime);
	void Destroy();
public:
	// Constructor
	explicit GameEngine() = default;
	// Copy constructor is deleted
	GameEngine(GameEngine const&) = delete;
	// Copy assignment is deleted
	GameEngine& operator=(GameEngine const&) = delete;
	// Start game loop
	void Start(int fps, int screenW, int screenH, const char *title, const char *first_scene);
	// Add a new scene to game
	void AddNewScene(const std::string name, IScene* scene);
	// Screen width
	int GetScreenWidth() const;
	// Screen height
	int GetScreenHeight() const;
	// function to retrieve instance and supports lazy initlalization
	static GameEngine& GetInstance();
};
#endif

