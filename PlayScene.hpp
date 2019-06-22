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

class PlayScene final : public IScene {
private:
	std::vector<Land *> lands;
	std::unordered_map<std::string, ResourceInfo> resources;
	Player* player;
	ALLEGRO_SAMPLE_INSTANCE *bgm_instance, *sfx_instance;
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
	void OnKeyDown(int keycode) override;
	void AddNewResourceType(std::string name, std::string img, int hp, int universality);
	ResourceInfo& GetResourceInfo(std::string name);
};
#endif

