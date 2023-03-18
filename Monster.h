#pragma once
#include "MonsterAnimation.h"

class Monster
{
private:
	
	sf::RectangleShape body;
	std::string currentType;
	AssetManager assetManager;
	int currentFrame;
	MonsterAnimation animation;
	bool changeType;
	bool error;
	int random;
	int counter;
	int randomNumber;
	std::string newType;

public:
	Monster(AssetManager& assetManager);
	void DrawMonster(sf::RenderWindow& window);
	void Update();

	void Error(bool isWrong);
	void Start();
};