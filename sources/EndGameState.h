#pragma once
#include "State.h"
#include "Game.h"
#include "Music.h"
#include "Combo.h"
#include "Monster.h"

class EndGameState :public State
{
public:
	EndGameState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic, int combo, bool onMaxCombo);

	void Init();
	void HandleInput();
	void Update();
	void Draw();

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	Monster* monster;
	sf::Clock frameClock;
	Combo* combos;
	sf::RectangleShape invisible;
	bool start = true;

	bool onMaxCombo;
	int combo;
	sf::Text comboText;
	float rightText = WIDTH;
	float leftText = -210;

	sf::RectangleShape menuButton;
	sf::RectangleShape statsButton;
	sf::RectangleShape newGameButton;

	sf::Text menuText;
	sf::Text statsText;
	sf::Text newGameText;

	sf::Vector2f buttonSize;
};