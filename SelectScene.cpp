#include "GameEngine.hpp"
#include "SelectScene.hpp"
#include "Music.hpp"

void SelectScene::Initialize() {
	Log(Debug) << "Select Scene Initialize";
	background = new Image("SelectSceneBackground.png", 0, 0);
	float dx = GameEngine::GetInstance().GetScreenWidth() / 6.0;
	for (int i = 0; i < 3; i++) {
		saves[i] = new ImageButton("square_button_light_gray.png", "square_button_gray.png", dx * (i * 2 + 1), 400, 400, 400, 0.5, 0);
		saves[i]->SetOnClick(std::bind(&SelectScene::Start, this));
		start[i] = new Text("START", "Metrool.ttf", 128, dx * (i * 2 + 1), 550, 100, 150, 200, 255, 0.5, 0);
	}
	bgm = Music::PlayBGM("LA.wav");
}
void SelectScene::Terminate() {
	Music::StopBGM(bgm);
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
	for (int i = 0; i < 3; i++) {
		saves[i]->Draw();
		if (saves[i]->IsMouseIn())
			start[i]->Draw();
	}
}
void SelectScene::Start() {
	GameEngine::GetInstance().SetNextScene("play");
}

