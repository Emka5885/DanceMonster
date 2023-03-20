#include "EndGameState.h"

EndGameState::EndGameState(GameDataReference data, sf::Text* scoreText) : data(data), scoreText(scoreText)
{
}

void EndGameState::Init()
{
	scoreText->setPosition((WIDTH / 2) - (scoreText->getGlobalBounds().width / 2), (HEIGHT / 2) - (scoreText->getGlobalBounds().height / 2));
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

	data->window.draw(*scoreText);

	data->window.display();
}
