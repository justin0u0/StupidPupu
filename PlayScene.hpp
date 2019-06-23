#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <vector>
#include <unordered_map>
#include "IScene.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "ResourceInfo.hpp"
#include "Setting.hpp"
#include "Bag.hpp"
#include "EnemyInfo.hpp"
#include "Point.hpp"
#include "Item.hpp"

class PlayScene final : public IScene {
private:
	std::unordered_map<std::string, ResourceInfo> resources;
	std::unordered_map<std::string, EnemyInfo> enemies;
	std::unordered_map<std::string, Item *> items; // item name, img name
	ALLEGRO_SAMPLE_INSTANCE *bgm_instance, *sfx_instance;
	Setting *setting;
	Bag *bag;
public:
	Point pivot;
	std::vector<Land *> lands;
	Player* player;
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
	void OnKeyDown(int keycode) override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	// setting buttons's callback function
	void BgmLouder();
	void BgmLower();
	void SfxLouder();
	void SfxLower();
	// For Resource
	void AddNewResourceType(std::string name, std::string img, int hp, int universality);
	ResourceInfo& GetResourceInfo(std::string name);
	void AddNewEnemyType(std::string name, std::string img, float w, float h
		, int hp, int dmg, float speed, float radius, float cooldown, int universality);
	EnemyInfo& GetEnemyInfo(std::string name);
	void AddNewItemType(std::string name, std::string img);
	void AddToPackage(std::string name, int amount);
	Land* GetPlayerLand() const;
	Point RepositionWithPivot(Point p);
};
#endif

