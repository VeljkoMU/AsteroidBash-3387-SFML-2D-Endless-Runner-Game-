#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
	InitSoundEffects();
	InitMusic();
}

void AudioPlayer::InitSoundEffects()
{
	explosion_audio_buffer_.loadFromFile("Resources/Audio/SoundEffects/explosion.wav");
	explosion_sound_.setBuffer(explosion_audio_buffer_);
	lasershot_audio_buffer_.loadFromFile("Resources/Audio/SoundEffects/lasersfx.wav");
	laser_sound_.setBuffer(lasershot_audio_buffer_);
	gameover_audio_buffer_.loadFromFile("Resources/Audio/SoundEffects/gameover.wav");
	gameover_sound_.setBuffer(gameover_audio_buffer_);
}

void AudioPlayer::InitMusic()
{
	mainmenu_music_.openFromFile("Resources/Audio/Music/title.wav");
	gameplay_music_.openFromFile("Resources/Audio/Music/music.wav");
	mainmenu_music_.setLoop(true);
	gameplay_music_.setLoop(true);
}

void AudioPlayer::PlayExplosionSound()
{
	explosion_sound_.play();
}

void AudioPlayer::PlayLaserSound()
{
	laser_sound_.play();
}

void AudioPlayer::PlayGameOverSound()
{
	if (!(gameover_sound_.getStatus() == sf::Sound::Playing))
	gameover_sound_.play();
}

void AudioPlayer::PlayGameplayMusic()
{
	if (!(gameplay_music_.getStatus() == sf::Sound::Playing))
	gameplay_music_.play();
}

void AudioPlayer::StopGameplayMusic()
{
	gameplay_music_.stop();
}

void AudioPlayer::PlayMainmenuMusic()
{
	if (!(mainmenu_music_.getStatus() == sf::Sound::Playing))
	mainmenu_music_.play();
}

void AudioPlayer::StopMainmenuMusic()
{
	mainmenu_music_.stop();
}
