#include "BagCell.hpp"
#include "Log.hpp"
#include "PlayScene.hpp"
#include "GameEngine.hpp" 

BagCell::BagCell(int id, float x, float y) {
	button = new ImageButton("square_out.png", "square_in.png", x, y, 130, 130);
	img = new Image("square_out.png", x, y, 130, 130, 0, 0);
	name = new Text("", "pirulen.ttf", 10, x + 65, y + 150, 255, 255, 255, 255, 0.5, 0.5);
	amount = new Text("", "pirulen.ttf", 10, x + 130, y + 100, 255, 255, 255, 255, 0, 0);
	img_name = "square_out.png";
	is_empty = true;
	this->id = id;
	button->SetOnClick(std::bind(&BagCell::ButtonCallback, this));
}
void BagCell::ButtonCallback() {
	PlayScene* playscene = dynamic_cast<PlayScene *>(GameEngine::GetInstance().GetActiveScene());
	Log(Debug) << this->id;
	playscene->bag->MixUpdate(id);
}
void BagCell::SetCallback(std::function<void(int id)> f) {
	callback = f;
}
void BagCell::Draw(bool able) const {
	button->Draw();
	if (able) {
		img->Draw();
		name->Draw();
		amount->Draw();
	}
}
void BagCell::Update(std::string img, std::string text, int num) {
	this->img->ChangeImage(img);
	name->ChangeText(text);
	amount->ChangeText(std::to_string(num));
	img_name = img;
}
void BagCell::ChangeItem(BagCell b) {
	Log(Debug) << "Bag Cell " << this->id << " changeItem to id " << b.id;
	this->img->ChangeImage(b.img_name);
	this->name->ChangeText(b.name->text);
	this->amount->ChangeText(b.amount->text);
	this->img_name = b.img_name;
	this->is_empty = false;
}

