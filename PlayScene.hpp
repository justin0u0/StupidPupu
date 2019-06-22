#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <vector>
#include "IScene.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "Setting.hpp"

class PlayScene final : public IScene {
private:
	std::vector<Land *> lands;
	Player* player;
	ALLEGRO_SAMPLE_INSTANCE *bgm_instance, *sfx_instance;
	Setting *setting;
public:
	void Initialize() override;
	void Terminate() override;
	void Draw() const override;
	void Update(float deltaTime) override;
	void OnKeyDown(int keycode) override;
	void BgmLouder();
	void BgmLower();
	void SfxLouder();
	void SfxLower();
};
#endif

