#ifndef IMAGEBUTTON_HPP
#define IMAGEBUTTON_HPP

#include <allegro5/bitmap.h>
#include <string>
#include <functional>
#include "Image.hpp"
#include "IControl.hpp"

class ImageButton : public Image, public IControl {
protected:
	bool mouseIn = false;
	// image when mouse is out of image
	ALLEGRO_BITMAP* image_out;
	// image when mouse is inside of image
	ALLEGRO_BITMAP* image_in;
	// function that need to be called if button clicked
	std::function<void(void)> onclick;
public:
	// Weather the imagebutton can be pressed
	bool Enabled = true;
	explicit ImageButton(std::string imgOut, std::string imgIn, float x, float y, float w=0, float h=0, float anchorX=0, float anchorY=0);
	// setter, since onclick is private
	void SetOnClick(std::function<void(void)> onclick);
	// left button: button&1
	// right button: button&2
	// middle button: button&4
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	bool IsMouseIn();
};
#endif
