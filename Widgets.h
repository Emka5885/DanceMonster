#pragma once
#include "AssetManager.h"

class Widgets
{
private:
	AssetManager assetManager;

	int score;
	sf::Text scoreText;

	int time;
	sf::Text timeText;
	sf::Clock timeClock;


public:
	Widgets(AssetManager& assetManager);

	void SetNewScore(int newScore);
	int GetScore();
	void SetScorePosition(sf::Vector2f newPosition);
	sf::FloatRect GetScoreGlobalBounds();

	void SetNewTime(int newTime);
	void TimeUpdate();

	void DrawWidgets(sf::RenderWindow& window);
};