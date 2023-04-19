#pragma once
#include "AssetManager.h"

class Music
{
private:
	sf::Music music;
	int currentMusic;

public:
	Music(AssetManager& assetManager, int num);

	void StartMusic();
	sf::Time MusicTime();
	void SetMusicVolume(int num);
};