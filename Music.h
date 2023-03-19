#pragma once
#include "AssetManager.h"

class Music
{
private:
	sf::Music music;
public:
	Music();

	void StartMusic();
	sf::Time MusicTime();
};