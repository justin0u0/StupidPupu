#ifndef BAG_HPP
#define BAG_HPP
#include "Image.hpp"
#include "ImageButton.hpp"
#include "Text.hpp"

class Bag : public Image , public IControl{
private:
//	Image *item[20];
	ImageButton *square[20];
//	Text *info[20];
	// for mix function
//	Image *mix_item[4];
//	ImageButton *mix_square[4];
//	Text *mix_info[4];
//  ImageButton *mix;
public:
	explicit Bag();
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;	
	void ReverseStatus();
	bool Status() const;
};
#endif

