#pragma once
#include "State.h"
#include "Game.h"
#include "ScrollBar.h"

class OptionsState :public State
{
public:
	OptionsState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic);
	void Save();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void CreateMusicOptionsButtons();
	void MusicOptionsPushBack(bool ScrollBar);
	void OptionsPushBack();

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	sf::RectangleShape backButton;

	sf::RectangleShape shape;
	sf::RectangleShape onShape;
	sf::RectangleShape offShape;

	sf::Text backText;
	sf::Text optionsText;
	sf::Text onText;
	sf::Text offText;

	sf::Text text;

	sf::Vector2f buttonSize;

	std::pair<std::pair<sf::RectangleShape, sf::Text>, bool> helper;
	std::vector<std::pair<std::pair<sf::RectangleShape, sf::Text>, bool>> options;
	std::vector<ScrollBar> scrollBars;
	std::vector<int> musicOptionsFromFile;
	std::vector<bool> optionsFromFile;
	std::pair<std::pair<sf::RectangleShape, sf::Text>, std::pair<sf::RectangleShape, sf::Text>> helper2;
	std::vector<std::pair<std::pair<sf::RectangleShape, sf::Text>, std::pair<sf::RectangleShape, sf::Text>>> OnOffButtons;
	ScrollBar* s;
};