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
	Monster(AssetManager& assetManager, bool mainMonster);
	void DrawMonster(sf::RenderWindow& window);
	void Update();

	void ChangePosition(sf::Vector2f xy);
	void ChangeScale(sf::Vector2f scale);

	void Error(bool isWrong);
	void Start();
	void Stop();

	bool stop;
};