#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <allegro5/allegro_audio.h>
#include <string>

class Music {
private:
	Music() = default;
public:
	static float bgm_volume;
	static float sfx_volume;
	static ALLEGRO_SAMPLE_ID PlayAudio(const std::string& audio);
	static ALLEGRO_SAMPLE_ID PlayBGM(const std::string& audio);
	static void StopBGM(ALLEGRO_SAMPLE_ID sample);
};
#endif

