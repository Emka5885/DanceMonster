#pragma once

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define RIGHT "right"
#define LEFT "left"
#define UP "up"
#define DOWN "down"
#define NORMAL "normal"
#define ERROR "error"
#define WIDTH 1200
#define HEIGHT 800

class AssetManager
{
public:
	AssetManager();
	~AssetManager() { }

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture& GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);

	void LoadMusic(std::string name, std::string fileName);
	std::string& GetMusic(std::string name);
	int musicsSize();

	void LoadSound(std::string name, std::string fileName);
	sf::Sound& GetSound(std::string name);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, std::string> musics;
	std::map<std::string, sf::Sound> sounds;
	sf::SoundBuffer soundBuffer;
};