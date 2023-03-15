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

	sf::Sprite playButton;
	sf::Sprite musicButton;
	sf::Sprite quitButton;
};
