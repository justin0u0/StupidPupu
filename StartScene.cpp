#include "GameEngine.hpp"
#include "StartScene.hpp"
#include "Music.hpp"
#include "Loader.hpp"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <chrono>

void StartScene::Initialize() {
	Log(Debug) << "Start Scene Initialize";
	background = new Image("StartSceneBackground.png", 0, 0);
	float halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	start_button = new ImageButton("start_button_out.png", "start_button_in.png", halfW, 650, 430, 130, 0.5, 0);
	start_button->SetOnClick(std::bind(&StartScene::Start, this));
	start_text = new Text("START", "Metrool.ttf", 95, halfW, 670, 0, 0, 0, 255, 0.5, 0);
	bgm = Music::PlayBGM("LA.ogg"); 
}
void StartScene::Terminate() {
	Music::StopBGM(bgm);
}
void StartScene::OnMouseDown(int button, int mx, int my) {
	start_button->OnMouseDown(button, mx, my);
}
void StartScene::OnMouseMove(int mx, int my) {
	start_button->OnMouseMove(mx, my);
}
void StartScene::Draw() const {
	IScene::Draw();
	background->Draw();
	start_button->Draw();
	start_text->Draw();
}
void StartScene::Start() {
	GameEngine::GetInstance().SetNextScene("select");
} 

