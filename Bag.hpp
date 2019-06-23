#ifndef BAG_HPP
#define BAG_HPP

#include <map>
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"
#include "Item.hpp"

struct BagCell {
	Image* img;
	ImageButton *button;
	Text *amount, *name;
	// Change Text: bag_cell[i].amount->ChangeText(std::to_string(new_amount));
};

class Bag : public Image , public IControl{
private:
	static const int Size = 20;
	static const int MixSize = 3;
  	ImageButton *mix_button;
  	std::map<Item *, int> package; // (item name, total amount)
public:
	BagCell bag_cell[Size];
	BagCell mix_cell[MixSize];
	explicit Bag();
	void Draw() const override;
	void Update();
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;	
	void ReverseStatus();
	bool Status() const;
	void AddItem(Item* item, int amount);
};
#endif

