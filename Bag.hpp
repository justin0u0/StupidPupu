#ifndef BAG_HPP
#define BAG_HPP

#include <map>
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"
#include "Item.hpp"
#include "BagCell.hpp"
#include <vector>

class Bag : public Image , public IControl {
private:
	const int Size = 20; // bag_cell size
	const int MixSize = 3; // mix_cell size
  	ImageButton *mix_button;
  	std::map<Item *, int> package; // (item name, total amount)
  	
public:
	std::vector<BagCell> bag_cell;
	explicit Bag();
	void Draw() const override;
	void BagUpdate();
	void MixUpdate(int id);
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;	
	void ReverseStatus();
	bool Status() const;
	void AddItem(Item* item, int amount);
};
#endif

