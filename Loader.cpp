#include "Loader.hpp"
#include "Log.hpp"

ALLEGRO_BITMAP* Loader::GetBitmap(std::string name) {
	if (bitmaps.count(name))
		return bitmaps[name];
	std::string path = bitmap_prefix + name;
	bitmaps[name] = al_load_bitmap(path.c_str());
	if (!bitmaps[name])
		Log(Error) << "failed to load image: " << path;
	Log(Info) << "Loaded image: " << path;
	return bitmaps[name];
}

ALLEGRO_FONT* Loader::GetFont(std::string name, int size) {
	if (fonts.count(name))
		return fonts[name];
	std::string path = font_prefix + name;
	fonts[name] = al_load_font(path.c_str(), size, 0);
	if (!fonts[name])
		Log(Error) << "failed to load font: " << path;
	Log(Info) << "Loaded font: " << path;
	return fonts[name];
}
