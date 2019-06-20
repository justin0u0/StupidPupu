#include <allegro5/allegro_audio.h>
#include "Music.hpp"
#include "Log.hpp"
#include "Loader.hpp"

float Music::bgm_volume = 1.0;
float Music::sfx_volume = 1.0;

ALLEGRO_SAMPLE_ID Music::PlayAudio(const std::string& audio) {
	ALLEGRO_SAMPLE* music = Loader::GetInstance().GetMusic(audio);
	ALLEGRO_SAMPLE_ID id;
	if (!al_play_sample(music, sfx_volume, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, &id))
		Log(Error) << "failed to play audio (once)";
	Log(Verbose) << "played audio (once)";
	return id;
}
ALLEGRO_SAMPLE_ID Music::PlayBGM(const std::string& audio) {
	ALLEGRO_SAMPLE* music = Loader::GetInstance().GetMusic(audio);
	ALLEGRO_SAMPLE_ID id;
	if (!al_play_sample(music, bgm_volume, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &id))
		Log(Error) << "failed to play audio (bgm)";
	Log(Info) << "played music (bgm)";
	return id;
}
void Music::StopBGM(ALLEGRO_SAMPLE_ID audio) {
	// No need to stop BGM by ourselves since the audio stops when the sample is destroyed.
	al_stop_sample(&audio);
	Log(Info) << "stopped audio (bgm)";
}

