#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include "IScene.hpp"
#include "Image.hpp"
#include "Text.hpp"
#include "ImageButton.hpp"

class StartScene final : public IScene {
private:
	Image* background;
	Text* start;
	ImageButton* game_start;
	ALLEGRO_SAMPLE_ID bgm;
public:
	explicit StartScene() = default;
	void Initialize() override;
	void Terminate() override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void Draw() const override;
	void Start(); 
};
#endif

