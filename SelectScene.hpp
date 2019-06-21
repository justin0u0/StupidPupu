#ifndef SELECT_SCENE_HPP
#define SELECT_SCENE_HPP

#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"

class SelectScene final : public IScene {
private:
	Image* background;
	ImageButton* saves[3];
	Text* start;
	ALLEGRO_SAMPLE_ID bgm;
public:
	explicit SelectScene() = default;
	void Initialize() override;
	void Terminate() override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void Draw() const override;
	void Start();
};
#endif

