#pragma once
#include "State.h"
#include "Game.h"

class EndGameState :public State
{
public:
	EndGameState(GameDataReference data);

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataReference data;
};