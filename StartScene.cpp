#include "GameEngine.hpp"
#include "StartScene.hpp"
#include "Music.hpp"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <chrono>

void StartScene::Initialize() {
	Log(Debug) << "Start Scene Initialize";
	background = new Image("StartSceneBackground.png", 0, 0);
	game_start = new ImageButton("start_button_out.png", "start_button_in.png", 540, 700, 430, 130, 0, 0);
	game_start->SetOnClick(std::bind(&StartScene::Start, this));
	bgm = Music::PlayBGM("LA.wav"); 
}
void StartScene::Terminate() {
	Music::StopBGM(bgm);
}
void StartScene::OnMouseDown(int button, int mx, int my) {
	game_start->OnMouseDown(button, mx, my);
}
void StartScene::OnMouseMove(int mx, int my) {
	game_start->OnMouseMove(mx, my);
}
void StartScene::Draw() const {
	IScene::Draw();
	background->Draw();
	game_start->Draw();
//	al_draw_filled_rectangle(540, 700, 970, 830, al_map_rgb(200, 100, 130));
}
void StartScene::Start() {
	GameEngine::GetInstance().SetNextScene("select");
} 

