#include "MainMenuState.h"
#include "GameState.h"
#include "StatsState.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataReference data) : data(data)
{
}

void MainMenuState::Init()
{
	buttonSize = { 450, 85 };
	data->buttons->NewButton(buttonSize, { WIDTH / 2 - buttonSize.x / 2, HEIGHT / 3 - buttonSize.y }, sf::Color::White, "New Game", 50, sf::Color::Black, 93, 12, "play_button");
	playButton = data->buttons->GetButton("play_button").first;
	playText = data->buttons->GetButton("play_button").second;

	buttonSize = { 450, 85 };
	data->buttons->NewButton(buttonSize, { WIDTH / 2 - buttonSize.x / 2, HEIGHT / 2 - buttonSize.y }, sf::Color::White, "Stats", 50, sf::Color::Black, 153, 12, "stats_button");
	statsButton = data->buttons->GetButton("stats_button").first;
	statsText = data->buttons->GetButton("stats_button").second;

	buttonSize = { 175, 85 };
	data->buttons->NewButton(buttonSize, { WIDTH - 50 - buttonSize.x, HEIGHT - 50 - buttonSize.y }, sf::Color::White, "Quitt", 50, sf::Color::Black, 12, 12, "quit_button");
	quitButton = data->buttons->GetButton("quit_button").first;
	quitText = data->buttons->GetButton("quit_button").second;
}

void MainMenuState::HandleInput()
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

		//input, if user click a particular button
		if (data->input.isButtonClicked(playButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new GameState(data)), true);
		}
		else if (data->input.isButtonClicked(statsButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StatsState(data)), true);
		}
	}
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(playButton);
	data->window.draw(playText);
	//data->window.draw(musicButton);
	data->window.draw(statsButton);
	data->window.draw(statsText);
	data->window.draw(quitButton);
	data->window.draw(quitText);

	data->window.display();
}
