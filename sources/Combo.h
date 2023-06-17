#pragma once
#include "AssetManager.h"
#include "Monster.h"

class Combo
{
private:
	AssetManager assetManager;
	sf::RectangleShape leftMonster;
	sf::RectangleShape rightMonster;
	int leftX;
	int rightX;
	Monster* mainMonster;
	sf::Clock moveClock;

public:
	Combo(AssetManager& assetManage, Monster* mainMonster);

	void UpdateMonsters(bool isCombo);

	void MonstersStart();
	void MonstersStop();

	void DrawMonsters(sf::RenderWindow& window);

	bool comboTime;
};