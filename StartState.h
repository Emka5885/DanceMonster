#pragma once
#include "State.h"
#include "Game.h"

class StartState :public State
{
public:
	StartState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;
	sf::Sound* menuSound;
	sf::Music* backgroundMusic;

	sf::Text counter;
	int counterNumber = 3;
	bool start = false;

	sf::Clock clock;
};
