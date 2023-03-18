#pragma once
#include "State.h"
#include "Game.h"
#include "BarOfNotes.h"
#include "Monster.h"

class GameState :public State
{
public:
	GameState(GameDataReference data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:

	GameDataReference data;

	BarOfNotes* barOfNotes;
	Monster* monster;

	sf::Clock dtClock;
	sf::Clock clock;
	sf::Clock frameClock;
    sf::Clock helperClock;

    bool start = true;
    bool errorStart = false;
	bool errorStop = false;

	int gameState;
	int score;
};