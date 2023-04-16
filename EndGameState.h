#pragma once
#include "State.h"
#include "Game.h"
#include "Music.h"

class EndGameState :public State
{
public:
	EndGameState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	sf::RectangleShape menuButton;
	sf::RectangleShape statsButton;

	sf::Text menuText;
	sf::Text statsText;

	sf::Vector2f buttonSize;
};