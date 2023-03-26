#pragma once
#include "State.h"
#include "Game.h"
#include "BarOfNotes.h"
#include "Monster.h"
#include "Music.h"
#include "Combo.h"

class GameState :public State
{
public:
	GameState(GameDataReference data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void SetNewScore();

private:

	GameDataReference data;

	BarOfNotes* barOfNotes;
	Monster* monster;
	Music* music;
	Combo* combos;

	sf::Clock dtClock;
	sf::Clock clock;
	sf::Clock frameClock;
    sf::Clock helperClock;
	sf::Clock combosClock;

    bool start = true;
    bool errorStart = false;
	bool errorStop = false;
	bool fail = false;

	//int gameState;
	int score;
	sf::Text scoreText;

	int combo;
	sf::Color backgroundColor;

	sf::Sound* errorSound;
};