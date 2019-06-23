#include "Bag.hpp"
#include "GameEngine.hpp"

Bag::Bag() : Image("bag.png", 0, 0
	, GameEngine::GetInstance().GetScreenWidth(), GameEngine::GetInstance().GetScreenHeight()) {
	for (int i = 0; i < Size; i++) {
		float x = (i % 4) * (150 + 33.6) + 33.6;
		float y = (i / 4) * (150 + 35) + 35;
		square[i] = new ImageButton("square_out.png", "square_in.png", x, y, 150, 150);
	}
	mix_square[0] = new ImageButton("square_out.png", "square_in.png", GameEngine::GetInstance().GetScreenWidth() / 2 + 384, GameEngine::GetInstance().GetScreenHeight() / 2 + 100, 150, 150, 0.5, 0.5);
	for (int i = 1; i < MixSize; i++) {
		float x = (i % 4 - 1) * (150 + 79.5) + 154.5 + GameEngine::GetInstance().GetScreenWidth() / 2;
		float y = GameEngine::GetInstance().GetScreenHeight() / 2 - 240;
		mix_square[i] = new ImageButton("square_out.png", "square_in.png", x, y, 150, 150, 0.5, 0.5);
	}
	mix_button = new ImageButton("mix_button_out.png", "mix_button_in.png",  GameEngine::GetInstance().GetScreenWidth() / 2 + 384, GameEngine::GetInstance().GetScreenHeight() - 200, 200, 130, 0.5, 0.5);
	if (Status())
		ReverseStatus();
}
void Bag::Draw() const {
	Image::Draw();
	for (int i = 0; i < Size; i++) {
		square[i]->Draw();
	}
	for (int i = 0; i < MixSize; i++)
		mix_square[i]->Draw();
	mix_button->Draw();
}
void Bag::OnMouseDown(int button, int mx, int my) {
	for (int i = 0; i < Size; i++)
		square[i]->OnMouseDown(button, mx, my);
	for (int i = 0; i < MixSize; i++)
		mix_square[i]->OnMouseDown(button, mx,my);
	mix_button->OnMouseDown(button, mx, my);
}
void Bag::OnMouseMove(int mx, int my) {
	for (int i = 0; i < Size; i++)
		square[i]->OnMouseMove(mx, my);
	for (int i = 0; i < MixSize; i++)
		mix_square[i]->OnMouseMove(mx, my);
	mix_button->OnMouseMove(mx, my);
}
void Bag::ReverseStatus() {
	this->visible = !this->visible;
	for (int i = 0; i < Size; i++) {
//		item[i]->visible = !buttons[i]->visible;
		square[i]->visible = !square[i]->visible;
//		info[i]->visible = !info[i]->visible;
		square[i]->enabled = !square[i]->enabled;
	}
	for (int i = 0; i < MixSize; i++) {
//		mix_item[i]->visible = !mix_item[i]->visible;
		mix_square[i]->visible = !mix_square[i]->visible;
//		mix_info[i]->visible = !mix_info[i]->visible;
		mix_square[i]->enabled = !mix_square[i]->enabled;
	}
	mix_button->visible = !mix_button->visible;
	mix_button->enabled = !mix_button->enabled;
}
bool Bag::Status() const {
	return this->visible;
}

