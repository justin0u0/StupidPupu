#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <allegro5/allegro.h>
#include <cstring>
#include <unordered_map>
#include "IScene.hpp"
#include "Image.hpp"
#include "Loader.hpp"
#include "Point.hpp"
 
class GameEngine final {
private:
	// frames per second, screen width, screen height
	int fps, screenW, screenH;
	// maximum ammount of samples that can be played simultaneously
	int reserve_samples;
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
	void ChangeScene(const std::string& name);
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
	void Start(int fps, int screenW, int screenH, int reserve_samples, const char* title, const std::string& first_scene);
	// Add a new scene to game
	void AddNewScene(const std::string& name, IScene* scene);
	// Setter for next_scene
	void SetNextScene(const std::string& name);
	// Get the pointer of active scene
	IScene* GetActiveScene() const;
	// Screen width
	int GetScreenWidth() const;
	// Screen height
	int GetScreenHeight() const;
	// Mouse position
	Point GetMousePosition() const;
	// Is key with keycode pressed
	bool IsKeyDown(int keycode) const;
	// Is pressing key left or 'a'
	bool IsLeft() const;
	// Is pressing key right or 'd'
	bool IsRight() const;
	// Is pressing key up or 'w'
	bool IsUp() const;
	// Is pressing key down or 's'
	bool IsDown() const;
	// function to retrieve instance and supports lazy initlalization
	static GameEngine& GetInstance();
};
#endif

