#include <allegro5/allegro.h>
#include "Tool.hpp"
#include "PlayScene.hpp"
#include "GameEngine.hpp"
 
Tool::Tool(std::string name, std::string img, float w, float h
	, int durablitly, int resource_damage, int enemy_damage, float attack_speed)
	: Sprite(img, -1, -1, w, h), Item(name, img) {
}
void Tool::PlayAnimation() {
	if (cooldown > 0)
		return ;
	cooldown = attack_speed;
	rotation = 10.0 / 180.0 * ALLEGRO_PI;
}
void Tool::Update(float deltaTime) {
	if (rotation > 0.5 * ALLEGRO_PI)
		rotation = 0.0;
	if (rotation > 0)
		rotation += 10.0 / 180.0 * ALLEGRO_PI;
	PlayScene* playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	position = playscene->player->position;
	flag = playscene->player->flag;
	// slightly move the tool
	if (flag == 0)
		position.x += 30;
	else
		position.x -= 30;
}

