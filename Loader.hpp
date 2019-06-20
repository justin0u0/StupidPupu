#ifndef LOADER_HPP
#define LOADER_HPP

#include <allegro5/allegro.h>
#include <string>
#include <unordered_map>
#include "Log.hpp"

// Each IScene has an loader
// Load Image, Sounds, Fonts
class Loader final {
private:
	const std::string bitmap_prefix = "./assets/images/";
	std::unordered_map<std::string, ALLEGRO_BITMAP *> bitmaps;
public:
	explicit Loader() = default;
	~Loader();
	ALLEGRO_BITMAP* GetBitmap(std::string name);
	ALLEGRO_BITMAP* GetBitmap(std::string name, int w, int h);
};
#endif

