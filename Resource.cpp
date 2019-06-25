#include "Resource.hpp"
#include "GameEngine.hpp"
#include "Resource.hpp"
#include "PlayScene.hpp"

Resource::Resource(std::string img, float x, float y, int health, std::string item)
	: Sprite(img, x, y, 50, 50), real_position(x, y), health(health) , item(item) {
}
void Resource::Update(float deltaTime) {
	position = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene())->RepositionWithPivot(real_position); 
	Sprite::Update(deltaTime);
}

