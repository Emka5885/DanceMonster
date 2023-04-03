#pragma once
#include "State.h"
#include "Game.h"

class StatsState :public State
{
public:
	StatsState(GameDataReference data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;

	sf::RectangleShape backButton;

	sf::Text backText;

	sf::Vector2f buttonSize;

	sf::RectangleShape line;
	sf::Text lineText;
	std::vector<std::pair<sf::RectangleShape, sf::Text>> statsLines;
};
