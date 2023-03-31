#include "EndGameState.h"

EndGameState::EndGameState(GameDataReference data) : data(data)
{
}

void EndGameState::Init()
{
	data->widgets->SetScorePosition({ (WIDTH / 2) - (data->widgets->GetScoreGlobalBounds().width / 2), (HEIGHT / 2) - (data->widgets->GetScoreGlobalBounds().height / 2) });

	quitButton = data->buttons->GetButton("quit_button").first;
	quitText = data->buttons->GetButton("quit_button").second;
}

void EndGameState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type || data->input.isButtonClicked(quitButton, sf::Mouse::Left, data->window))
		{
			data->window.close();
			delete data->buttons;
			delete data->widgets;
		}
	}
}

void EndGameState::Update(float dt)
{
}

void EndGameState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->widgets->DrawWidgets(data->window);
	data->window.draw(quitButton);
	data->window.draw(quitText);

	data->window.display();
}
