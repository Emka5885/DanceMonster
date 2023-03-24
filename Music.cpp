#include "Music.h"

Music::Music(AssetManager& assetManager)
{
	currentMusic = rand() % assetManager.musicsSize();

	music.openFromFile(assetManager.GetMusic(std::to_string(currentMusic)));
}

void Music::StartMusic()
{
	music.setVolume(25);
	music.play();
}

sf::Time Music::MusicTime()
{
	return music.getDuration();
}
