#pragma once
#include "State.h"
#include "Game.h"
#include "BarOfNotes.h"
#include "Monster.h"
#include "Music.h"
#include "Combo.h"
#include "Widgets.h"

class GameState :public State
{
public:
	GameState(GameDataReference data, sf::Sound* menuSound, sf::Music* menuBackgroundMusic);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:

	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* menuBackgroundMusic;

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

	int counter;
	int combo;
	sf::Color backgroundColor;

	sf::Sound* errorSound;

	std::vector<bool> optionsFromFile;
	std::vector<int> musicOptionsFromFile;
};