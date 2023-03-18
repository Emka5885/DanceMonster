#include "MainMenuState.h"
#include "GameState.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataReference data) : data(data)
{
}

void MainMenuState::Init()
{
	data->assets.LoadTexture("newGame", "resources/menu/Play.png");

	playButton.setTexture(this->data->assets.GetTexture("newGame"));

	playButton.setScale(7, 7);
	playButton.setPosition((WIDTH / 2) - (playButton.getGlobalBounds().width / 2), (HEIGHT / 2) - (playButton.getGlobalBounds().height / 2));
	//loadTexture for playButton, musicButton and quitButton; set textures; set positions
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
		if (data->input.isSpriteClicked(playButton, sf::Mouse::Left, data->window))
		{
			data->machine.AddState(stateReference(new GameState(data)), true);
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
	//data->window.draw(musicButton);
	//data->window.draw(quitButton);

	data->window.display();
}
