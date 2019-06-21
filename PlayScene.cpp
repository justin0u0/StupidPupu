#include "PlayScene.hpp"
#include "GameEngine.hpp"

#include "Sprite.hpp"
void PlayScene::Initialize() {
	int halfW = GameEngine::GetInstance().GetScreenWidth() / 2;
	int halfH = GameEngine::GetInstance().GetScreenHeight() / 2;
	lands.emplace_back(new Land("land_advanced.png", halfW, halfH));
}
void PlayScene::Terminate() {
}
void PlayScene::Draw() const {
	IScene::Draw();
//	lands[0]->Draw();
	for (auto land : lands)
		land->Draw();
}
void PlayScene::Update(float deltaTime) {
	for (auto land : lands)
		land->Update(deltaTime);
}

