#ifndef BAGCELL_HPP
#define BAGCELL_HPP

#include <functional>
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"

// a cell in bag
class BagCell {
private:
	std::function<void(int id)> callback;
public:
	Image* img;
	ImageButton *button;
	Text *amount, *name;
	std::string img_name;
	bool is_empty;
	int id;
	explicit BagCell(int id, float x, float y);
	void SetCallback(std::function<void(int id)>);
	void ButtonCallback();
	void Draw(bool able) const;
	void Update(std::string img, std::string text, int num);
	void ChangeItem(BagCell b);
//	explicit BagCell(int id, float x, float y);
}; 
#endif

