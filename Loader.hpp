#ifndef LOADER_HPP
#define LOADER_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <string>
#include <unordered_map>
#include "Log.hpp"

// Load Image, Sounds, Fonts
class Loader final {
private:
	const std::string bitmap_prefix = "./assets/images/";
	const std::string font_prefix = "./assets/fonts/";
	const std::string music_prefix = "./assets/audios/";
	std::unordered_map<std::string, ALLEGRO_BITMAP *> bitmaps;
	std::unordered_map<std::string, ALLEGRO_FONT*> fonts;
	std::unordered_map<std::string, ALLEGRO_SAMPLE*> music;
public:
	explicit Loader() = default;
	~Loader(); // TODO: clear loader
	ALLEGRO_BITMAP* GetBitmap(std::string name);
	ALLEGRO_BITMAP* GetBitmap(std::string name, int w, int h);
	ALLEGRO_FONT* GetFont(std::string, int size);
	ALLEGRO_SAMPLE* GetMusic(std::string);
	// TODO: FreeBitmap, FreeFont, FreeMusic
	static Loader& GetInstance();
};
#endif

