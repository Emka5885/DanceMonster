#pragma once
#include "State.h"
#include "Game.h"

class MainMenuState :public State
{
public:
	MainMenuState(GameDataReference data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;

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

	sf::SoundBuffer menuSoundBuffer;
	sf::Sound menuSound;

	std::vector<int> musicOptionsFromFile;
};
