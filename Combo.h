#pragma once
#include "AssetManager.h"

class Combo
{
private:
	AssetManager assetManager;
	sf::CircleShape mainShape;

public:
	Combo(AssetManager& assetManage);

	void ChangeMainShapeColor();

	void DrawColors(sf::RenderWindow& window);
};