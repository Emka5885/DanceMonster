#pragma once
#include "State.h"
#include "Game.h"
#include "Music.h"
#include "Combo.h"
#include "Monster.h"

class EndGameState :public State
{
public:
	EndGameState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic, int combo);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	Monster* monster;
	sf::Clock frameClock;
	Combo* combos;
	sf::RectangleShape invisible;
	bool start = true;

	int combo;
	sf::Text comboText;
	float rightText = WIDTH;
	float leftText = -210;

	sf::RectangleShape menuButton;
	sf::RectangleShape statsButton;

	sf::Text menuText;
	sf::Text statsText;

	sf::Vector2f buttonSize;
};