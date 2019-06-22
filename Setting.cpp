#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro.h>
#include <string>

#include "GameEngine.hpp"
#include "Setting.hpp"
#include "Music.hpp"
#include "Loader.hpp"
#include "Log.hpp"

Setting::Setting() : Image("setting.png", GameEngine::GetInstance().GetScreenWidth() / 2 + 200, 450, 400, 500, 0, 0) {
	int set_x = GameEngine::GetInstance().GetScreenWidth() / 2 + 200;
	int set_y = 450;
	int set_w = 400;
	int set_h = 500;
	// music bgm
	bgm_label = new Text("BGM", "BodoniFLF-BoldItalic.ttf", 48, set_x + 10, set_y + 10, 0, 0, 0, 255, 0, 0);
	bgm_lower = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x + 150, set_y + 10, 50, 50, 0, 0);
	bgm_louder = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + set_w - 70, set_y + 10, 50, 50, 0, 0);
	bgm_value = new Text("100 %", "BodoniFLF-BoldItalic.ttf", 50, set_x + set_w / 2 + 65, set_y + 10, 0, 0, 0, 255, 0.5, 0);
	// music sfx
	sfx_label = new Text("SFX", "BodoniFLF-BoldItalic.ttf", 48, set_x + 10, set_y + 100, 0, 0, 0, 255, 0, 0);
	sfx_lower = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x + 150, set_y + 100, 50, 50, 0, 0);
	sfx_louder = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + set_w - 70, set_y + 100, 50, 50, 0, 0);
	sfx_value = new Text("100 %", "BodoniFLF-BoldItalic.ttf", 50, set_x + set_w / 2 + 65, set_y + 100, 0, 0, 0, 255, 0.5, 0);
}
void Setting::Draw() const {
	Image::Draw();
	bgm_louder->Draw();
	bgm_lower->Draw();
	sfx_louder->Draw();
	sfx_lower->Draw();
	bgm_value->Draw();
	bgm_label->Draw();
	sfx_value->Draw();
	sfx_label->Draw();
}
void Setting::OnMouseDown(int button, int mx, int my) {
	bgm_louder->OnMouseDown(button, mx, my);
	bgm_lower->OnMouseDown(button, mx, my);
	sfx_louder->OnMouseDown(button, mx, my);
	sfx_lower->OnMouseDown(button, mx, my);
}
void Setting::OnMouseMove(int mx, int my) {
	bgm_louder->OnMouseMove(mx, my);
	bgm_lower->OnMouseMove(mx, my);
	sfx_louder->OnMouseMove(mx, my);
	sfx_lower->OnMouseMove(mx, my);
}
void Setting::ReverseStatus() {
	this->visible = (this->visible) ? false : true;
	bgm_louder->visible = (bgm_louder->visible) ? false : true;
	bgm_lower->visible = (bgm_lower->visible) ? false : true;
	sfx_louder->visible = (sfx_louder->visible) ? false : true;
	sfx_lower->visible = (sfx_lower->visible) ? false : true;
	bgm_value->visible = (bgm_value->visible) ? false : true;
	bgm_label->visible = (bgm_label->visible) ? false : true;
	sfx_value->visible = (sfx_value->visible) ? false : true;
	sfx_label->visible = (sfx_label->visible) ? false : true;
}
bool Setting::Status() const {
	return this->visible;
}

