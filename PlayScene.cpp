#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h> 
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <chrono>
#include "PlayScene.hpp"
#include "GameEngine.hpp"

void PlayScene::Initialize() {
	int halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfH = GameEngine::GetInstance().GetScreenHeight() / 2;
	lands.emplace_back(new Land("land_advanced.png", halfW, halfH));
	player = new Player("ghost_transparent.png", halfW, halfH);
	// for adjust music LIVE
	// bgm
	//Creates a sample stream, using the supplied data. 
	bgm_instance = al_create_sample_instance(Loader::GetInstance().GetMusic("play.ogg"));
	// Set the playback mode
	al_set_sample_instance_playmode(bgm_instance, ALLEGRO_PLAYMODE_LOOP);
	// sample_stream must be attached to a voice or mixer
	al_attach_sample_instance_to_mixer(bgm_instance, al_get_default_mixer());
	al_play_sample_instance(bgm_instance);
	// sfx
	sfx_instance = al_create_sample_instance(Loader::GetInstance().GetMusic("click.wav"));
	al_set_sample_instance_playmode(sfx_instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(sfx_instance, al_get_default_mixer());
//	al_play_sample_instance(sfx_instance);
}
void PlayScene::Terminate() {
}
void PlayScene::Draw() const {
	IScene::Draw();
	al_clear_to_color(al_map_rgb(70, 150, 255));
	for (auto& land : lands)
		land->Draw();
	player->Draw();
}
void PlayScene::Update(float deltaTime) {
	for (auto& land : lands)
		land->Update(deltaTime);
	player->Update(deltaTime);
}
void PlayScene::OnKeyDown(int keycode) {
}

