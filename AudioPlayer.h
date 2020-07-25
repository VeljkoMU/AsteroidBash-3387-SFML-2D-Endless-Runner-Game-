#pragma once
#include "SFMLINCLUDE.h"

class AudioPlayer
{
private:
	sf::SoundBuffer explosion_audio_buffer_;
	sf::SoundBuffer lasershot_audio_buffer_;
	sf::SoundBuffer gameover_audio_buffer_;
	sf::Sound explosion_sound_;
	sf::Sound laser_sound_;
	sf::Sound gameover_sound_;

	sf::Music mainmenu_music_;
	sf::Music gameplay_music_;
	
public:
	AudioPlayer();
	void InitSoundEffects();
	void InitMusic();
	void PlayExplosionSound();
	void PlayLaserSound();
	void PlayGameOverSound();
	void PlayGameplayMusic();
	void StopGameplayMusic();
	void PlayMainmenuMusic();
	void StopMainmenuMusic();

};