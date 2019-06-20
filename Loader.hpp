#ifndef LOADER_HPP
#define LOADER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <unordered_map>
#include "Log.hpp"

class Loader final {
private:
	const std::string bitmap_prefix = "./assets/images/";
	const std::string font_prefix = "./assets/fonts";
	std::unordered_map<std::string, ALLEGRO_BITMAP *> bitmaps;
	std::unordered_map<std::string, ALLEGRO_FONT*> fonts;
public:
	explicit Loader() = default;
	~Loader();
	ALLEGRO_BITMAP* GetBitmap(std::string name);
	ALLEGRO_FONT* GetFont(std::string, int size);
};
#endif

