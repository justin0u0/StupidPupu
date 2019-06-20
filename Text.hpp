#ifndef TEXT_HPP
#define TEXT_HPP

#include <allegro5/allegro_font.h>
#include <allegro5/color.h>
#include <string>

#include "IObject.hpp"

class Text : public IObject {
protected:
	ALLEGRO_FONT* font;
public:
	std::string text;
	ALLEGRO_COLOR color;
	explicit Text(const std::string& text, const std::string& font, int fontSize, float x, float y
		, unsigned char r=0, unsigned char g=0, unsigned char b=0, unsigned char a=255
		, float anchorX=0, float anchorY=0);
	void Draw() const override;
	int GetTextWidth() const;
	int GetTextHeight() const;
};
#endif

