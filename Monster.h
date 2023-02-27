#pragma once
#include "AssetManager.h"

class Monster
{
private:
	
	sf::RectangleShape body;
	std::string currentType;
	float totalTime;
	float switchTime;

public:
	Monster(AssetManager& assetManager);
	void DrawMonster(sf::RenderWindow& window);
	void Update(std::string type);
};