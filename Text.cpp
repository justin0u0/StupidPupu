#include <allegro5/allegro_font.h>

#include "IObject.hpp"
#include "Text.hpp"
#include "Point.hpp"
#include "Loader.hpp"

Text::Text(const std::string& text, const std::string& font, int fontSize, float x, float y
	, unsigned char r, unsigned char g, unsigned char b, unsigned char a, float anchorX, float anchorY)
	: IObject(x, y, 0, 0, anchorX, anchorY), font(Loader::GetInstance().GetFont(font, fontSize))
	, text(text), color(al_map_rgba(r, g, b, a)) {
}
void Text::Draw() const {
	al_draw_text(font, color, position.x - anchor.x * GetTextWidth(), position.y - anchor.y * GetTextHeight(), 0, text.c_str());
}
int Text::GetTextWidth() const {
	return al_get_text_width(font, text.c_str());
}
int Text::GetTextHeight() const {
	return al_get_font_line_height(font);
}

