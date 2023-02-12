#pragma once
#include "AssetManager.h"

#define RIGHT "right"
#define LEFT "left"
#define UP "up"
#define DOWN "down"

class Resources
{
private:
	AssetManager assetManager;
public:
	Resources()
	{
		assetManager.LoadTexture("left", "resources/arrows/LeftArrow.png");
		assetManager.LoadTexture("right", "resources/arrows/RightArrow.png");
		assetManager.LoadTexture("down", "resources/arrows/DownArrow.png");
		assetManager.LoadTexture("up", "resources/arrows/UpArrow.png");
	}

	sf::Texture& getArrow(std::string type)
	{
		return assetManager.GetTexture(type);
	}
};