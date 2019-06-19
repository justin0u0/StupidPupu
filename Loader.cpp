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

