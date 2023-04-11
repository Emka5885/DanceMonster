#pragma once
#include "State.h"
#include "Game.h"
#include "ScrollBar.h"

class MusicState :public State
{
public:
	MusicState(GameDataReference data);
	void Save();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void CreateMusicOptionsButtons();
	void MusicOptionsPushBack(bool ScrollBar);

private:
	GameDataReference data;

	sf::RectangleShape backButton;

	sf::RectangleShape shape;

	sf::Text backText;
	sf::Text musicText;

	sf::Text text;

	sf::Vector2f buttonSize;

	std::pair<std::pair<sf::RectangleShape, sf::Text>, bool> helper;
	std::vector<std::pair<std::pair<sf::RectangleShape, sf::Text>, bool>> musicOptions;
	std::vector<ScrollBar> musicScrollBars;
	std::vector<int> musicOptionsFromFile;
	ScrollBar* s;
};