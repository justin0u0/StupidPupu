#include <allegro5/allegro.h>
#include "IScene.hpp"

void IScene::Draw() const {
	al_clear_to_color(al_map_rgb(0, 0, 0));
}