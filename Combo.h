#pragma once
#include "AssetManager.h"
#include "Monster.h"

class Combo
{
private:
	AssetManager assetManager;
	sf::CircleShape mainShape;
	Monster* leftMonster;
	Monster* rightMonster;

public:
	Combo(AssetManager& assetManage);

	void ChangeColors();

	void MonstersStart();
	void MonstersStop();

	void DrawColors(sf::RenderWindow& window);
	void DrawMonsters(sf::RenderWindow& window);
};