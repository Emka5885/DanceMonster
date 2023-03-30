#include "MainMenuState.h"
#include "GameState.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataReference data) : data(data)
{
	buttons = new Buttons(data->assets);
}

void MainMenuState::Init()
{
	//playButton.setFillColor(sf::Color::White);
	//playButton.setSize({450, 100});
	//playButton.setPosition((WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (HEIGHT / 3) - (playButton.getGlobalBounds().height / 2));
	//loadTexture for playButton, musicButton and quitButton; set textures; set positions

	buttonSize = { 175, 85 };
	buttons->NewButton(buttonSize, { WIDTH - 50 - buttonSize.x, HEIGHT - 50 - buttonSize.y }, sf::Color::White, "Quitt", 50, sf::Color::Black, "quit_button");
	quitButton = buttons->GetButton("quit_button").first;
	quitText = buttons->GetButton("quit_button").second;

	//quitButton.setScale(7, 7);
	//quitButton.setPosition(WIDTH - (playButton.getGlobalBounds().width + 50), HEIGHT - (playButton.getGlobalBounds().height + 50));
}

void MainMenuState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data->window.close();
		}

		//input, if user click a particular button
		if (data->input.isButtonClicked(playButton, sf::Mouse::Left, data->window))
		{
			data->machine.AddState(stateReference(new GameState(data)), true);
		}
		else if (data->input.isButtonClicked(quitButton, sf::Mouse::Left, data->window))
		{
			data->window.close();
			delete buttons;
			delete data->widgets;
		}
	}
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	//data->window.draw(playButton);
	//data->window.draw(musicButton);
	data->window.draw(quitButton);
	data->window.draw(quitText);

	data->window.display();
}
