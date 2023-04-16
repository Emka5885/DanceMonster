#pragma once
#include "State.h"
#include "Game.h"

class MainMenuState :public State
{
public:
	MainMenuState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	sf::RectangleShape playButton;
	sf::RectangleShape statsButton;
	sf::RectangleShape optionsButton;
	sf::RectangleShape quitButton;

	sf::Text playText;
	sf::Text statsText;
	sf::Text optionsText;
	sf::Text quitText;
	sf::Text title;

	sf::Vector2f buttonSize;

	std::vector<int> musicOptionsFromFile;
};
