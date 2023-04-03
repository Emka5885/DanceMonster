#pragma once
#include "AssetManager.h"

class Widgets
{
private:
	AssetManager assetManager;

	int score;
	sf::Text scoreText;

	int time;
	int musicTime;
	sf::Text timeText;
	sf::Clock timeClock;


public:
	Widgets(AssetManager& assetManager);

	void SetNewScore(int newScore);
	int GetScore();
	void SetScorePosition(sf::Vector2f newPosition);
	sf::FloatRect GetScoreGlobalBounds();

	void SetNewTime(int newTime, bool newMusic);
	int GetTime();
	void TimeUpdate();

	void DrawScore(sf::RenderWindow& window);
	void DrawTime(sf::RenderWindow& window);
};