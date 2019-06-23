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

class PlayScene final : public IScene {
private:
	std::vector<Land *> lands;
	std::unordered_map<std::string, ResourceInfo> resources;
	Player* player;
	ALLEGRO_SAMPLE_INSTANCE *bgm_instance, *sfx_instance;
	Setting *setting;
	Bag *bag;
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
	void OnKeyDown(int keycode) override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void BgmLouder();
	void BgmLower();
	void SfxLouder();
	void SfxLower();
	void AddNewResourceType(std::string name, std::string img, int hp, int universality);
	ResourceInfo& GetResourceInfo(std::string name);
};
#endif

