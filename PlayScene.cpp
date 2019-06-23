#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <chrono>
#include <algorithm>

#include "PlayScene.hpp"
#include "GameEngine.hpp"
#include "Music.hpp"

void PlayScene::Initialize() {
	int halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfH = GameEngine::GetInstance().GetScreenHeight() / 2;
	// Create Player
	player = new Player("ghost_transparent.png", halfW, halfH);
	// Add resources
	AddNewResourceType("Tree", "tree_transparent.png", 100, 10);
	AddNewResourceType("Stone", "resource_stone.png", 300, 9);
	// Add enemies
	AddNewEnemyType("Slime", "slime.png", 100, 1, 30, 50, 60, 10);
	// Add lands and corresponding resources
	lands.emplace_back(new Land("land_advanced.png", halfW, halfH));
	lands.back()->AddNewResourceType("Tree");
	lands.back()->AddNewResourceType("Stone");
	lands.back()->AddNewEnemyType("Slime");
	// Create Setting
	setting = new Setting();
	// Create bgm
	bgm_instance = al_create_sample_instance(Loader::GetInstance().GetMusic("play.ogg"));
	al_set_sample_instance_playmode(bgm_instance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(bgm_instance, al_get_default_mixer());
	al_play_sample_instance(bgm_instance);
	Log(Info) << "Start to play bgm";
	// Create sfx
	sfx_instance = al_create_sample_instance(Loader::GetInstance().GetMusic("click.wav"));
	al_set_sample_instance_playmode(sfx_instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(sfx_instance, al_get_default_mixer());
	al_play_sample_instance(sfx_instance);
	Log(Info) << "PLay sfx once";
	// Set setting onclick button
	setting->SetValue(std::bind(&PlayScene::BgmLouder, this), 0);
	setting->SetValue(std::bind(&PlayScene::BgmLower, this), 1);
	setting->SetValue(std::bind(&PlayScene::SfxLouder, this), 2);
	setting->SetValue(std::bind(&PlayScene::SfxLower, this), 3);
}
void PlayScene::Terminate() {
}
void PlayScene::Draw() const {
	IScene::Draw();
	al_clear_to_color(al_map_rgb(70, 150, 255));
	for (auto& land : lands)
		land->Draw();
	player->Draw();
	setting->Draw();
}
void PlayScene::Update(float deltaTime) {
	for (auto& land : lands)
		land->Update(deltaTime);
	player->Update(deltaTime);
}
void PlayScene::OnKeyDown(int keycode) {
	IScene::OnKeyDown(keycode);
	if (keycode == ALLEGRO_KEY_ESCAPE) {
		if (setting->Status())
			Log(Info) << "Close Setting";
		else 
			Log(Info) << "Open Setting";
		setting->ReverseStatus();
	}
}
void PlayScene::OnMouseDown(int button, int mx, int my) {
	setting->OnMouseDown(button, mx, my);
}
void PlayScene::OnMouseMove(int mx, int my) {
	setting->OnMouseMove(mx, my);
}
void PlayScene::BgmLouder() {
	float volume = setting->bgm_value + 0.1;
	setting->bgm_value = std::min((float)1.0, volume);
	al_set_sample_instance_gain(bgm_instance, setting->bgm_value);
	Music::bgm_volume = setting->bgm_value;
}
void PlayScene::BgmLower() {
	float volume = setting->bgm_value - 0.1;
	setting->bgm_value = std::max((float)0.0, volume);
	al_set_sample_instance_gain(bgm_instance, setting->bgm_value);
	Music::bgm_volume = setting->bgm_value;
}
void PlayScene::SfxLouder() {
	float volume = setting->sfx_value + 0.1;
	setting->sfx_value = std::min((float)1.0, volume);
	al_set_sample_instance_gain(sfx_instance, setting->sfx_value);
	Music::sfx_volume = setting->sfx_value;
}
void PlayScene::SfxLower() {
	float volume = setting->sfx_value - 0.1;
	setting->sfx_value = std::max((float)0.0, volume);
	al_set_sample_instance_gain(sfx_instance, setting->sfx_value);
	Music::sfx_volume = setting->sfx_value;
}
void PlayScene::AddNewResourceType(std::string name, std::string img, int hp, int universality) {
	if (resources.count(name))
		Log(Error) << "Cannot add same resource type with same name";
	resources.insert(make_pair(name, ResourceInfo(name, img, hp, universality)));
}
ResourceInfo& PlayScene::GetResourceInfo(std::string name) {
	if (!resources.count(name))
		Log(Error) << "Resource type " << name << " has not been added.";
	return resources.at(name);
}
void PlayScene::AddNewEnemyType(std::string name, std::string img
	, int hp, int dmg, float speed, float radius, float cooldown, int universality) {
	if (enemies.count(name))
		Log(Error) << "Cannot add same enemy type with same name";
	enemies.insert(make_pair(name, EnemyInfo(name, img, hp, dmg, speed, radius, cooldown, universality)));
}
EnemyInfo& PlayScene::GetEnemyInfo(std::string name) {
	if (!enemies.count(name))
		Log(Error) << "Enemy type " << name << " has not been added.";
	return enemies.at(name);
}
Player* PlayScene::GetPlayer() const {
	return player;
}

