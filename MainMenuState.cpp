#include "MainMenuState.h"

MainMenuState::MainMenuState(GameDataReference data) : data(data)
{
}

void MainMenuState::Init()
{
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
	}
}

void MainMenuState::Update(float dt)
{
}

void MainMenuState::Draw(float dt)
{
	data->window.clear();

	//data->window.draw(playButton);
	//data->window.draw(musicButton);
	//data->window.draw(quitButton);

	data->window.display();
}
