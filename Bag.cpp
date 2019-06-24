#include <functional>
#include "Bag.hpp"
#include "GameEngine.hpp"
#include "Item.hpp"

Bag::Bag() : Image("bag.png", 0, 0
	, GameEngine::GetInstance().GetScreenWidth(), GameEngine::GetInstance().GetScreenHeight()) {
	float screenW = GameEngine::GetInstance().GetScreenWidth();
	float screenH = GameEngine::GetInstance().GetScreenHeight();
	for (int i = 0; i < Size; i++) {
		float x = (i % 4) * (130 + 49.6) + 49.6;
		float y = (i / 4) * (130 + 50) + 10;
		bag_cell.emplace_back((BagCell){i, x, y});
		bag_cell[i].SetCallback(std::bind(Bag::MixUpdate, this, std::placeholders::_1));
	}
	// id = 20
	bag_cell.emplace_back((BagCell){Size, screenW / 2 + 319, screenH / 2 + 5});
	bag_cell[Size].SetCallback(std::bind(Bag::MixUpdate, this, std::placeholders::_1));
	for (int i = 1; i < MixSize; i++) {
		float x = 170 + 300 * (i - 1) + screenW / 2;
		float y = GameEngine::GetInstance().GetScreenHeight() / 2 - 200 - 65;
		bag_cell.emplace_back((BagCell){Size + i, x, y});
		bag_cell[Size + i].SetCallback(std::bind(Bag::MixUpdate, this, std::placeholders::_1));
	}
	mix_button = new ImageButton("mix_button_out.png", "mix_button_in.png",  screenW / 2 + 384,  screenH - 200, 200, 130, 0.5, 0.5);
	if (Status())
		ReverseStatus();
}
void Bag::Draw() const {
	Image::Draw();
	for (int i = 0; i < Size; i++)
		bag_cell[i].Draw(i < package.size() && this->visible);
	for (int i = 0; i < MixSize; i++)
		bag_cell[i + Size].Draw(!bag_cell[i + Size].is_empty);
	mix_button->Draw();
}
void Bag::BagUpdate() { 
	int i = 0;
	// sort item location again
	for (auto m : package) {
		if (m.second != 0) {
			bag_cell[i].Update(m.first->GetImage(), m.first->name, m.second);
			i++;
		}
	}
}
void Bag::MixUpdate(int id) {
	Log(Debug) << "Hahaha " << id;
	if (id < Size) { // click bag_cell
		int ok = 0;
		for (int i = 0; i < MixSize; i++) {
			if (bag_cell[i + Size].is_empty) {
				ok = i;
				break;
			}
		}
		Log(Debug) << "ok: " << ok;
		if (ok) { // change the img from bag_cell[id] to mix_cell[ok]
			bag_cell[ok + Size].ChangeItem(bag_cell[id]);
			Item *old = new Item(bag_cell[id].name->text, bag_cell[id].img_name);
			if (package.count(old)) {
				Log(Debug) << "delete bag_cell" << id;
				package.at(old) = 0;
				BagUpdate();
			}
		}
	} else { // click mix_cell
		if (!bag_cell[id].is_empty) {
			Item *old = new Item(bag_cell[id].name->text, bag_cell[id].img_name);
			AddItem(old, std::stoi(bag_cell[id].amount->text));
			bag_cell[id].is_empty = true;
			BagUpdate();
		}
	}
}
void Bag::OnMouseDown(int button, int mx, int my) {
	Log(Debug) << "Mouse Down " << mx << ' ' << my;
	for (int i = 0; i < Size; i++) {
		Log(Debug) << "Button " << i << " check mouse down";
		Log(Debug) << "ButtonID: " << bag_cell[i].id;
		bag_cell[i].button->OnMouseDown(button, mx, my);
	}
	for (int i = 0; i < MixSize; i++) {
		Log(Debug) << "Button " << i + Size << "check mouse down";
		bag_cell[i + Size].button->OnMouseDown(button, mx,my);
	}
	mix_button->OnMouseDown(button, mx, my);
}
void Bag::OnMouseMove(int mx, int my) {
	for (int i = 0; i < Size; i++)
		bag_cell[i].button->OnMouseMove(mx, my);
	for (int i = 0; i < MixSize; i++)
		bag_cell[i + Size].button->OnMouseMove(mx, my);
	mix_button->OnMouseMove(mx, my);
}
void Bag::ReverseStatus() {
	this->visible = !this->visible;
	for (int i = 0; i < Size; i++) {
		if (i < package.size()) {
			bag_cell[i].img->visible = !bag_cell[i].button->visible;
			bag_cell[i].name->visible = !bag_cell[i].button->visible;
			bag_cell[i].amount->visible = !bag_cell[i].button->visible;
		}
		bag_cell[i].button->visible = !bag_cell[i].button->visible;
		bag_cell[i].button->enabled = !bag_cell[i].button->enabled;
	}
	for (int i = Size; i < MixSize + Size; i++) {
		bag_cell[i].button->visible = !bag_cell[i].button->visible;
		bag_cell[i].button->enabled = !bag_cell[i].button->enabled;
	}
	mix_button->visible = !mix_button->visible;
	mix_button->enabled = !mix_button->enabled;
}
bool Bag::Status() const {
	return this->visible;
}
void Bag::AddItem(Item* item, int amount) {
	package[item] += amount;
	BagUpdate();
}


