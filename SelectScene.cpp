#include "GameEngine.hpp"
#include "SelectScene.hpp"
#include "Music.hpp"

void SelectScene::Initialize() {
	background = new Image("SelectSceneBackground.png", 0, 0, 0, 0, 0.5, 0.5);
	float dx = GameEngine::GetInstance().GetScreenWidth() / 3.0;
	for (int i = 0; i < 3; i++) {
		saves[i] = new ImageButton("square_button.png", "square_button.png", dx * (i + 0.5), 400, 0.5, 0);
		saves[i]->SetOnClick(std::bind(&SelectScene::Start, this));
	}
	Music::PlayBGM("LA.wav");
}
void SelectScene::Terminate() {
}
void SelectScene::OnMouseDown(int button, int mx, int my) {
	for (int i = 0; i < 3; i++)
		saves[i]->OnMouseDown(button, mx, my);
}
void SelectScene::OnMouseMove(int mx, int my) {
	for (int i = 0; i < 3; i++)
		saves[i]->OnMouseMove(mx, my);
}
void SelectScene::Draw() const {
	IScene::Draw();
	background->Draw();
	for (int i = 0; i < 3; i++)
		saves[i]->Draw();
}
void SelectScene::Start() {
	// TODO: change scene
}
/*
#ifndef SELECT_SCENE_HPP
#define SELECT_SCENE_HPP

class SelectScene final : public IScene {
private:
	Image* background;
	ImageButton* saves[3];
	Text* start;
public:
	void Initialize() override;
	void OnMouseDown() override;
	void OnMouseMove() override;
	void Terminate() override;
};
#endif
*/

