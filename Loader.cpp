#include "Loader.hpp"
#include "Log.hpp"

Loader::~Loader() {
}
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
ALLEGRO_BITMAP* Loader::GetBitmap(std::string name, int w, int h) {
	std::string rename = name + std::to_string(w) + "x" + std::to_string(h);
	if (bitmaps.count(rename))
		return bitmaps[rename];
	std::string path = bitmap_prefix + name;
	ALLEGRO_BITMAP* bmp = al_load_bitmap(path.c_str());
	if (!bmp)
		Log(Error) << "failed to load image: " << path;
	ALLEGRO_BITMAP* resized_bmp = al_create_bitmap(w, h);
	ALLEGRO_BITMAP* prev_target = al_get_target_bitmap();
	if (!resized_bmp)
		Log(Error) << "failed to create bitmap when creating resizing image: " << path;
	al_set_target_bitmap(resized_bmp);
	al_draw_scaled_bitmap(bmp, 0, 0, al_get_bitmap_width(bmp), al_get_bitmap_height(bmp), 0, 0, w, h, 0);
	al_set_target_bitmap(prev_target);
	al_destroy_bitmap(bmp);
	Log(Info) << "Loaded image: " << path << " scaled to " << w << "x" << h;
	bitmaps[rename] = resized_bmp;
	return bitmaps[rename];
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
ALLEGRO_SAMPLE* Loader::GetMusic(std::string name) {
	if (music.count(name))
		return music[name];
	std::string path = music_prefix + name;
	music[name] = al_load_sample(path.c_str());
	if (!music[name])
		Log(Error) << "failed to load audio: " << path;
	Log(Info) << "Loaded audio: " << path;
	return music[name];
}
Loader& Loader::GetInstance() {
	static Loader loader;
	return loader;
}

