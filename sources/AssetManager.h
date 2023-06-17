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
#define SCROLLBAR_BACKGROUND 10
#define SCROLLBAR_HANDLE 10


class AssetManager
{
public:
	AssetManager();
	~AssetManager() { }

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture* GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);

	void LoadMusic(std::string name, std::string fileName);
	std::string& GetMusic(std::string name);
	int musicsSize();

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, std::string> musics;
};