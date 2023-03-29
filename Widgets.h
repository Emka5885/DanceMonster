#pragma once
#include "AssetManager.h"

class Widgets
{
private:
	AssetManager assetManager;
	int score;
	sf::Text scoreText;

public:
	Widgets(AssetManager& assetManager);

	void SetNewScore(int newScore);
	void DrawScore(sf::RenderWindow& window);
	int GetScore();
	void SetScorePosition(sf::Vector2f newPosition);
	sf::FloatRect GetScoreGlobalBounds();
};