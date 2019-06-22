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
void PlayScene::AddNewResourceType(std::string name, std::string img, int maximum_hp, int universality) {
	if (resources.count(name))
		Log(Error) << "Cannot add same resource type with same name";
	resources.insert(make_pair(name, ResourceInfo(name, img, maximum_hp, universality)));
}
ResourceInfo& PlayScene::GetResourceInfo(std::string name) {
	if (!resources.count(name))
		Log(Error) << "Resource type " << name << " has not been added.";
	return resources.at(name);
}

