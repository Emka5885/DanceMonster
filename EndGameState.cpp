#include "EndGameState.h"

EndGameState::EndGameState(GameDataReference data) : data(data)
{
}

void EndGameState::Init()
{
	data->widgets->SetScorePosition({ (WIDTH / 2) - (data->widgets->GetScoreGlobalBounds().width / 2), (HEIGHT / 2) - (data->widgets->GetScoreGlobalBounds().height / 2) });
}

void EndGameState::HandleInput()
{
}

void EndGameState::Update(float dt)
{
}

void EndGameState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->widgets->DrawScore(data->window);

	data->window.display();
}
