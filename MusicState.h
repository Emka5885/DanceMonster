#pragma once
#include "State.h"
#include "Game.h"

class MusicState :public State
{
public:
	MusicState(GameDataReference data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;

	sf::RectangleShape backButton;

	sf::Text backText;
	sf::Text musicText;

	sf::Vector2f buttonSize;
};