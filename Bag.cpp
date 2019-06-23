#include "Bag.hpp"
#include "GameEngine.hpp"

Bag::Bag() : Image("bag.png", 0, 0
	, GameEngine::GetInstance().GetScreenWidth(), GameEngine::GetInstance().GetScreenHeight()) {
	for (int i = 0; i < 20; i++) {
		float x = (i % 4) * (150 + 33.6) + 33.6;
		float y = (i / 4) * (150 + 35) + 35;
		square[i] = new ImageButton("square_out.png", "square_in.png", x, y, 150, 150);
	}
	if (Status())
		ReverseStatus();
}
void Bag::Draw() const {
	Image::Draw();
	for (int i = 0; i < 20; i++)
		square[i]->Draw();
}
void Bag::OnMouseDown(int button, int mx, int my) {
	for (int i = 0; i < 20; i++)
		square[i]->OnMouseDown(button, mx, my);
	
}
void Bag::OnMouseMove(int mx, int my) {
	for (int i = 0; i < 20; i++)
		square[i]->OnMouseMove(mx, my);
}
void Bag::ReverseStatus() {
	this->visible = !this->visible;
	for (int i = 0; i < 20; i++) {
//		item[i]->visible = !buttons[i]->visible;
		square[i]->visible = !square[i]->visible;
//		info[i]->visible = !info[i]->visible;
		square[i]->enabled = !square[i]->enabled;
	}
//	for (int i = 0; i < 4; i++) {
//		mix_item[i]->visible = !mix_item[i]->visible;
//		mix_square[i]->visible = !mix_square[i]->visible;
//		mix_info[i]->visible = !mix_info[i]->visible;
//		mix_square[i]->enalbed = !mix_square[i]->enabled;
//	}
//	mix->visible = !mix->visible;
//	mix->enabled = !mix->enabled;
}
bool Bag::Status() const {
	return this->visible;
}

