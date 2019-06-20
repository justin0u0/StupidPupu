#include <allegro5/allegro.h>
#include "IScene.hpp"

IScene::IScene() {
	loader = new Loader();
}
void IScene::Draw() const {
	al_clear_to_color(al_map_rgb(0, 0, 0));
}
