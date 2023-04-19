#include "Music.h"

Music::Music(AssetManager& assetManager, int num)
{
	currentMusic = rand() % assetManager.musicsSize();

	music.openFromFile(assetManager.GetMusic(std::to_string(currentMusic)));

	SetMusicVolume(num);
}

void Music::StartMusic()
{
	music.play();
}

sf::Time Music::MusicTime()
{
	return music.getDuration();
}

void Music::SetMusicVolume(int num)
{
	music.setVolume(num);
}
