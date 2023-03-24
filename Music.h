#pragma once
#include "AssetManager.h"

class Music
{
private:
	sf::Music music;
	int currentMusic;

public:
	Music(AssetManager& assetManager);

	void StartMusic();
	sf::Time MusicTime();
};