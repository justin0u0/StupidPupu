#include <string>
#include <cmath>
#include "GameEngine.hpp"
#include "Setting.hpp"
#include "Music.hpp"
#include "Loader.hpp"
#include "Log.hpp"

Setting::Setting() : Image("settings.png", GameEngine::GetInstance().GetScreenWidth() / 2, GameEngine::GetInstance().GetScreenHeight() / 2, 400, 500, 0.5, 0.5) {
	int set_x = GameEngine::GetInstance().GetScreenWidth() / 2;
	int set_y = GameEngine::GetInstance().GetScreenHeight() / 2;
	int set_w = GetBitmapWidth(); // 400
	int set_h = GetBitmapHeight(); // 500
	bgm_value = 1.0;
	sfx_value = 1.0;
	// music bgm
	labels[0] = new Text("BGM", "pirulen.ttf", 24, set_x - 150, set_y - 200, 0, 0, 0, 255, 0.5, 0.5);
	buttons[1] = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x - 50, set_y -200, 50, 50, 0.5, 0.5);
	buttons[0] = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + 150, set_y - 200, 50, 50, 0.5, 0.5);
	labels[1] = new Text("100 %", "pirulen.ttf", 24, set_x + 50, set_y - 200, 0, 0, 0, 255, 0.5, 0.5);
	// music sfx
	labels[2] = new Text("SFX", "pirulen.ttf", 24, set_x - 150, set_y - 120, 0, 0, 0, 255, 0.5, 0.5);
	buttons[3] = new ImageButton("bgm_lower_out.png", "bgm_lower_in.png", set_x - 50, set_y - 120, 50, 50, 0.5, 0.5);
	buttons[2] = new ImageButton("bgm_louder_out.png", "bgm_louder_in.png", set_x + 150, set_y -120, 50, 50, 0.5, 0.5);
	labels[3] = new Text("100 %", "pirulen.ttf", 24, set_x + 50, set_y - 120, 0, 0, 0, 255, 0.5, 0.5);
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
	labels[1]->ChangeText(std::to_string(static_cast<int>(round(bgm_value * 100))) + " %");
	labels[3]->ChangeText(std::to_string(static_cast<int>(round(sfx_value * 100))) + " %");
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

