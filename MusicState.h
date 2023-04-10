#pragma once
#include "State.h"
#include "Game.h"
#include "ScrollBar.h"

class MusicState :public State
{
public:
	MusicState(GameDataReference data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void CreateMusicOptionsButtons();

private:
	GameDataReference data;

	sf::RectangleShape backButton;

	sf::RectangleShape menu;

	sf::Text backText;
	sf::Text musicText;

	sf::Text menuText;

	sf::Vector2f buttonSize;

	std::vector<std::pair<std::pair<sf::RectangleShape, sf::Text>, ScrollBar>> musicOptionsButtons;
	ScrollBar* s;

	int counter;
};