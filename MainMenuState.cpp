#include "MainMenuState.h"
#include "StartState.h"
#include "StatsState.h"
#include "OptionsState.h"
#include <iostream>
#include "EndGameState.h"

MainMenuState::MainMenuState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic) : data(data), menuSound(menuSound), backgroundMusic(backgroundMusic)
{
}

void MainMenuState::Init()
{
	buttonSize = { 450, 85 };
	data->buttons->NewButton(buttonSize, { WIDTH / 2 - buttonSize.x / 2, HEIGHT / 3 - buttonSize.y + 50 }, sf::Color::White, "New Game", 50, sf::Color::Black, "play_button");
	playButton = data->buttons->GetButton("play_button").first;
	playText = data->buttons->GetButton("play_button").second;

	data->buttons->NewButton(buttonSize, { WIDTH / 2 - buttonSize.x / 2, HEIGHT / 3 + 125 - buttonSize.y + 50 }, sf::Color::White, "Stats", 50, sf::Color::Black, "stats_button");
	statsButton = data->buttons->GetButton("stats_button").first;
	statsText = data->buttons->GetButton("stats_button").second;

	data->buttons->NewButton(buttonSize, { WIDTH / 2 - buttonSize.x / 2, HEIGHT / 3 + 250 - buttonSize.y + 50 }, sf::Color::White, "Options", 50, sf::Color::Black, "options_button");
	optionsButton = data->buttons->GetButton("options_button").first;
	optionsText = data->buttons->GetButton("options_button").second;

	buttonSize = { 175, 85 };
	data->buttons->NewButton(buttonSize, { WIDTH - 50 - buttonSize.x, HEIGHT - 50 - buttonSize.y }, sf::Color::White, "Quitt", 50, sf::Color::Black, "quit_button");
	quitButton = data->buttons->GetButton("quit_button").first;
	quitText = data->buttons->GetButton("quit_button").second;

	title.setString("Dance Monster");
	title.setFillColor(sf::Color::White);
	title.setOutlineColor(sf::Color::Black);
	title.setOutlineThickness(4);
	title.setCharacterSize(100);
	title.setFont(data->assets.GetFont("standardFont"));
	title.setPosition({ WIDTH / 2 - title.getGlobalBounds().width / 2, 50 });
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
			menuSound->play();
			data->machine.RemoveState();
			//data->machine.AddState(stateReference(new StartState(data, menuSound, backgroundMusic)), true, true);
			data->machine.AddState(stateReference(new EndGameState(data, menuSound, backgroundMusic, 100)), true);
		}
		else if (data->input.isButtonClicked(statsButton, sf::Mouse::Left, data->window))
		{
			menuSound->play();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StatsState(data, menuSound, backgroundMusic)), true);
		}
		else if (data->input.isButtonClicked(optionsButton, sf::Mouse::Left, data->window))
		{
			menuSound->play();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new OptionsState(data, menuSound, backgroundMusic)), true);
		}
	}
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(title);
	data->window.draw(playButton);
	data->window.draw(playText);
	data->window.draw(optionsButton);
	data->window.draw(optionsText);
	data->window.draw(statsButton);
	data->window.draw(statsText);
	data->window.draw(quitButton);
	data->window.draw(quitText);

	data->window.display();
}
