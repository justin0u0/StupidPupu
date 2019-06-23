#include "Bag.hpp"
#include "GameEngine.hpp"

Bag::Bag() : Image("bag.png", 0, 0
	, GameEngine::GetInstance().GetScreenWidth(), GameEngine::GetInstance().GetScreenHeight()) {
	int screenW = GameEngine::GetInstance().GetScreenWidth();
	int screenH = GameEngine::GetInstance().GetScreenHeight();
	for (int i = 0; i < Size; i++) {
		float x = (i % 4) * (130 + 49.6) + 49.6;
		float y = (i / 4) * (130 + 50) + 10;
		bag_cell[i].button = new ImageButton("square_out.png", "square_in.png", x, y, 130, 130);
	}
	mix_cell[0].button = new ImageButton("square_out.png", "square_in.png", screenW / 2 + 384, screenH / 2 + 70, 130, 130, 0.5, 0.5);
	for (int i = 1; i < MixSize; i++) {
		float x = 170 + 65 + 300 * (i - 1) + screenW / 2;
		float y = GameEngine::GetInstance().GetScreenHeight() / 2 - 200;
		mix_cell[i].button = new ImageButton("square_out.png", "square_in.png", x, y, 130, 130, 0.5, 0.5);
	}
	mix_button = new ImageButton("mix_button_out.png", "mix_button_in.png",  screenW / 2 + 384,  screenH - 200, 200, 130, 0.5, 0.5);
	if (Status())
		ReverseStatus();
}
void Bag::Draw() const {
	Image::Draw();
	for (int i = 0; i < Size; i++) {
		bag_cell[i].button->Draw();
		if (i < package.size() && this->visible) {
			bag_cell[i].img->Draw();
			bag_cell[i].name->Draw();
		}
	}
	for (int i = 0; i < MixSize; i++)
		mix_cell[i].button->Draw();
	mix_button->Draw();
}
void Bag::Update() {
	int i = 0;
	// sort item location again
	for (auto m : package) {
		float x = bag_cell[i].button->position.x;
		float y = bag_cell[i].button->position.y;
		bag_cell[i].img  = new Image(m.first->GetImage(), x, y, 130, 130, 0, 0); 
		bag_cell[i].name = new Text(m.first->GetName(), "pirulen.ttf", 10, x + 65, y + 150, 255, 255, 255, 255, 0.5, 0.5); 
		i++;
	}
}
void Bag::OnMouseDown(int button, int mx, int my) {
	for (int i = 0; i < Size; i++)
		bag_cell[i].button->OnMouseDown(button, mx, my);
	for (int i = 0; i < MixSize; i++)
		mix_cell[i].button->OnMouseDown(button, mx,my);
	mix_button->OnMouseDown(button, mx, my);
}
void Bag::OnMouseMove(int mx, int my) {
	for (int i = 0; i < Size; i++)
		bag_cell[i].button->OnMouseMove(mx, my);
	for (int i = 0; i < MixSize; i++)
		mix_cell[i].button->OnMouseMove(mx, my);
	mix_button->OnMouseMove(mx, my);
}
void Bag::ReverseStatus() {
	this->visible = !this->visible;
	for (int i = 0; i < Size; i++) {
		if (i < package.size()) {
			bag_cell[i].img->visible = !bag_cell[i].button->visible;
			bag_cell[i].name->visible = !bag_cell[i].button->visible;
		}
		bag_cell[i].button->visible = !bag_cell[i].button->visible;
		bag_cell[i].button->enabled = !bag_cell[i].button->enabled;
	}
	for (int i = 0; i < MixSize; i++) {
//		mix_item[i]->visible = !mix_item[i]->visible;
		mix_cell[i].button->visible = !mix_cell[i].button->visible;
//		mix_info[i]->visible = !mix_info[i]->visible;
		mix_cell[i].button->enabled = !mix_cell[i].button->enabled;
	}
	mix_button->visible = !mix_button->visible;
	mix_button->enabled = !mix_button->enabled;
}
bool Bag::Status() const {
	return this->visible;
}
void Bag::AddItem(Item* item, int amount) {
	package[item] += amount;
	Update();
}

