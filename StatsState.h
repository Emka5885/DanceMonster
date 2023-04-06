#pragma once
#include "State.h"
#include "Game.h"
#include "ScrollBar.h"

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

	ScrollBar* scrollBar;

	sf::RectangleShape backButton;

	sf::Text backText;

	sf::Vector2f buttonSize;

	bool checkCounter;
	int counter = 0;
	float counterLine = 0;
	float margin;
	sf::RectangleShape line;
	Texts lineText;
	sf::Text statsText;
	std::vector<std::string> statsLinesText;
	std::vector<std::pair<sf::RectangleShape, Texts>> statsLines;
};
