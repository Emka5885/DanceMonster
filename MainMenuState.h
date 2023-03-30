#pragma once
#include "State.h"
#include "Game.h"
#include "Buttons.h"

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
	sf::RectangleShape musicButton;
	sf::RectangleShape quitButton;

	sf::Text quitText;

	sf::Vector2f buttonSize;
	Buttons* buttons;
};
