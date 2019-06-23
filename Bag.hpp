#ifndef BAG_HPP
#define BAG_HPP
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"
#include <unordered_map>

struct BagCell {
	Image* img;
	ImageButton *button;
	Text *amount, *name;
};

class Bag : public Image , public IControl{
private:
	static const int Size = 20;
	static const int MixSize = 3;
  	ImageButton *mix_button;
  	std::unordered_map<std::string, int> package; // (item name, total amount)
public:
	BagCell bag_cell[Size];
	BagCell mix_cell[MixSize];
	explicit Bag();
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;	
	void ReverseStatus();
	bool Status() const;
};
#endif

