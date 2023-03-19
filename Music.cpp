#include "Music.h"

Music::Music()
{
	music.openFromFile("resources/music/Luke-Bergs-Golden-State-of-Mind_MasterMP3.wav");
}

void Music::StartMusic()
{
	music.play();
}

sf::Time Music::MusicTime()
{
	return music.getDuration();
}
