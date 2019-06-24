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
#include "Collider.hpp"

void PlayScene::Initialize() {
	int halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfH = GameEngine::GetInstance().GetScreenHeight() / 2;
	// Set Pivot
	pivot = Point(0, 0);
	// Create Player
	player = new Player("ghost_transparent.png", halfW, halfH);
	// Add resources
	AddNewResourceType("Tree", "tree_transparent.png", 100, 10);
	AddNewResourceType("Stone", "resource_stone.png", 300, 9);
	// Add enemies
	AddNewEnemyType("Slime", "slime.png", 50, 50, 100, 1, 30, 50, 60, 10);
	// Add lands and corresponding resources
	lands.emplace_back(new Land("land_advanced.png", halfW, halfH));
	lands.back()->AddNewResourceType("Tree");
	lands.back()->AddNewResourceType("Stone");
	lands.back()->AddNewEnemyType("Slime");
	// Add Tools
	AddNewItemType("Wood Pickaxe", "wood_pickaxe.png");
	AddNewItemType("Stone Pickaxe", "stone_pickaxe.png");
	AddNewItemType("Iron Pickaxe", "iron_pickaxe.png");
	AddNewItemType("Slime Pickaxe", "slime_pickaxe.png");
	AddNewItemType("Wood Sword", "wood_sword.png");
	AddNewItemType("Stone Sword", "stone_sword.png");
	AddNewItemType("Iron Sword", "iron_sword.png");
	// Add Foods
	AddNewItemType("Blueberry", "blueberry.png");
	AddNewItemType("Redberry", "redberry.png");
	AddNewItemType("Heal Potion (once)", "red_potion.png");
	AddNewItemType("Heal Potion (continuous)", "blue_potion");
	// Add Materials
	AddNewItemType("Wood", "wood.png");
	AddNewItemType("Stone", "stone.png");
	AddNewItemType("Coal", "coal.png");
	AddNewItemType("Iron", "iron.png");
	// Create Setting
	setting = new Setting();
	bag = new Bag();
	// Create bgm
	Log(Debug) << "Hi";
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
	
	// Testings 1
	Log(Debug) << "Add 2 stone to package";
	AddToPackage("Stone", 2);
	Log(Debug) << "Add 3 wood to package";
	AddToPackage("Wood", 3);
	
	// Testings 2
	player->ChangeTool(new Tool("Wood Pickaxe", "wood_pickaxe.png", 50, 50, 100, 9, 5, 0.8));
}
void PlayScene::Terminate() {
}
void PlayScene::Draw() const {
	al_clear_to_color(al_map_rgb(70, 150, 255));
	for (auto& land : lands)
		land->Draw();
	player->Draw();
	bag->Draw();
	setting->Draw();
}
void PlayScene::Update(float deltaTime) {
//	Log(Debug) << "Pivot: " << pivot.x << ' ' << pivot.y;
//	Log(Debug) << "Player(pos): " << player->position.x << ' ' << player->position.y;
//	Log(Debug) << "Player(real): " << player->real_position.x << ' ' << player->real_position.y;
//	Log(Debug) << "Land(pos): " << lands[0]->position.x << ' ' << lands[0]->position.y;
//	Log(Debug) << "Land(real): " << lands[0]->real_position.x << ' ' << lands[0]->real_position.y;
//	Log(Debug) << "Land Left Up(real)" << lands[0]->LeftUpCorner().x << ' ' << lands[0]->LeftUpCorner().y;
	for (auto& land : lands)
		land->Update(deltaTime);
	player->Update(deltaTime);
}
void PlayScene::OnKeyDown(int keycode) {
	IScene::OnKeyDown(keycode);
	if (keycode == ALLEGRO_KEY_ESCAPE) {
		if (!bag->Status()) {
			if (setting->Status())
				Log(Debug) << "Close Setting";
			else
				Log(Debug) << "Open Setting";
			setting->ReverseStatus();
		}
	} else if (keycode == ALLEGRO_KEY_Q) {
		if (!setting->Status()) {
			if (bag->Status())
				Log(Debug) << "Close Bag";
			else
				Log(Debug) << "Open Bag";
			bag->ReverseStatus();		
		}
	}
}
void PlayScene::OnMouseDown(int button, int mx, int my) {
	setting->OnMouseDown(button, mx, my);
	bag->OnMouseDown(button, mx, my);
	player->OnMouseDown(button, mx, my);
}
void PlayScene::OnMouseMove(int mx, int my) {
	setting->OnMouseMove(mx, my);
	bag->OnMouseMove(mx, my);
	player->OnMouseMove(mx, my);
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
void PlayScene::AddNewEnemyType(std::string name, std::string img, float w, float h
	, int hp, int dmg, float speed, float radius, float cooldown, int universality) {
	if (enemies.count(name))
		Log(Error) << "Cannot add same enemy type with same name";
	enemies.insert(make_pair(name, EnemyInfo(name, img, w, h, hp, dmg, speed, radius, cooldown, universality)));
}
EnemyInfo& PlayScene::GetEnemyInfo(std::string name) {
	if (!enemies.count(name))
		Log(Error) << "Enemy type " << name << " has not been added.";
	return enemies.at(name);
}
void PlayScene::AddNewItemType(std::string name, std::string img) {
	if (items.count(name))
		Log(Error) << "Cannot add same item type with same name.";
	items.insert(make_pair(name, new Item(name, img)));
}
void PlayScene::AddToPackage(std::string name, int amount) {
	if (!items.count(name))
		Log(Error) << "Item type " << name << " has not been added.";
	bag->AddItem(items[name], amount);
}
Land* PlayScene::GetPlayerLand() const {
	for (auto& land : lands) {
		if (Collider::PointInRectangle(player->position, land->LeftUpCorner(), land->RightDownCorner())) {
			return land;
		}
	}
	Log(Error) << "Player is not on any land";
	return nullptr;
}
Point PlayScene::RepositionWithPivot(Point p) {
	return p - pivot;
}

