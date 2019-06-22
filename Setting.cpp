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

Setting::Setting() : Image("settings.png", GameEngine::GetInstance().GetScreenWidth() / 2, GameEngine::GetInstance().GetScreenHeight() / 2, 400, 500, 0.5, 0.5) {
	int set_x = GameEngine::GetInstance().GetScreenWidth() / 2;
	int set_y = GameEngine::GetInstance().GetScreenHeight() / 2;
	int set_w = GetBitmapWidth();
	int set_h = GetBitmapHeight();
	bgm_value = 1.0;
	sfx_value = 1.0;
	// music bgm
	labels[0] = new Text("BGM", "BodoniFLF-BoldItalic.ttf", 48, set_x + 10, set_y + 10, 0, 0, 0, 255, 0.5, 0.5);
	buttons[1] = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x + 150, set_y + 10, 50, 50, 0.5, 0.5);
	buttons[0] = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + set_w - 70, set_y + 10, 50, 50, 0.5, 0.5);
	labels[1] = new Text("100 %", "BodoniFLF-BoldItalic.ttf", 50, set_x + set_w / 2 + 65, set_y + 10, 0, 0, 0, 255, 0.5, 0.5);
	// music sfx
	labels[2] = new Text("SFX", "BodoniFLF-BoldItalic.ttf", 48, set_x + 10, set_y + 100, 0, 0, 0, 255, 0.5, 0.5);
	buttons[3] = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x + 150, set_y + 100, 50, 50, 0.5, 0.5);
	buttons[2] = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + set_w - 70, set_y + 100, 50, 50, 0.5, 0.5);
	labels[3] = new Text("100 %", "BodoniFLF-BoldItalic.ttf", 50, set_x + set_w / 2 + 65, set_y + 100, 0, 0, 0, 255, 0.5, 0.5);
	if (Status())
		ReverseStatus();
}
void Setting::Draw() const {
	Image::Draw();
	for (int i = 0; i < 4; i++) {
		buttons[i]->Draw();
		labels[i]->Draw();
	}
}
void Setting::OnMouseDown(int button, int mx, int my) {
	for (int i = 0; i < 4; i++)
		buttons[i]->OnMouseDown(button, mx, my);
}
void Setting::OnMouseMove(int mx, int my) {
	for (int i = 0; i < 4; i++)
		buttons[i]->OnMouseMove(mx, my);
}
void Setting::ReverseStatus() {
	this->visible = !this->visible;
	for (int i = 0; i < 4; i++) {
		buttons[i]->visible = !buttons[i]->visible;
		buttons[i]->enabled = !buttons[i]->enabled;
		labels[i]->visible = !labels[i]->visible;
	}
}
bool Setting::Status() const {
	return this->visible;
}
void Setting::SetValue(std::function<void(void)> onclick_function, int id) {
	buttons[id]->SetOnClick(onclick_function);
	Log(Debug) << "button" << id << " complete SetOnClick";
}

