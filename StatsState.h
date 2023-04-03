#pragma once
#include "State.h"
#include "Game.h"

struct Texts
{
	sf::Text scoreText;
	sf::Text dash;
	sf::Text timeText;
};

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

	float counterLine = 0;
	float margin;
	sf::RectangleShape line;
	Texts lineText;
	sf::Text statsText;
	std::vector<std::string> statsLinesText;
	std::vector<std::pair<sf::RectangleShape, Texts>> statsLines;
};
