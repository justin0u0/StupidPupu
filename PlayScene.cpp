#include "PlayScene.hpp"
#include "GameEngine.hpp"

void PlayScene::Initialize() {
	int halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfH = GameEngine::GetInstance().GetScreenHeight() / 2;
	lands.emplace_back(new Land("land_advanced.png", halfW, halfH));
	player = new Player("ghost_transparent.png", halfW, halfH);
}
void PlayScene::Terminate() {
}
void PlayScene::Draw() const {
	IScene::Draw();
	for (auto& land : lands)
		land->Draw();
	player->Draw();
}
void PlayScene::Update(float deltaTime) {
	for (auto& land : lands)
		land->Update(deltaTime);
	player->Update(deltaTime);
}
void OnMouseDown(int button, int mx, int my) {
}

