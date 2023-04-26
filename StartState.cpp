#include "StartState.h"
#include "GameState.h"
#include <iostream>

StartState::StartState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic) : data(data), menuSound(menuSound), backgroundMusic(backgroundMusic)
{
}

void StartState::Init()
{
	counter.setString(std::to_string(counterNumber));
	counter.setFillColor(sf::Color::White);
	counter.setOutlineColor(sf::Color::Black);
	counter.setOutlineThickness(4);
	counter.setCharacterSize(250);
	counter.setFont(data->assets.GetFont("standardFont"));
	counter.setPosition({ WIDTH / 2 - counter.getGlobalBounds().width / 2,  HEIGHT / 2 - counter.getGlobalBounds().height / 2 - counter.getGlobalBounds().height / 3 });

	clock.restart();
}

void StartState::HandleInput()
{
	sf::Event event;

	while (data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data->window.close();
			delete data->buttons;
			delete data->widgets;
		}
	}

	if (counterNumber <= 0)
	{
		if (clock.getElapsedTime() >= sf::seconds(0.1))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new GameState(data, menuSound, backgroundMusic)), true, true);
		}
	}
	else if (clock.getElapsedTime() >= sf::seconds(1))
	{
		counterNumber--;
		counter.setString(std::to_string(counterNumber));
		counter.setPosition({ WIDTH / 2 - counter.getGlobalBounds().width / 2,  HEIGHT / 2 - counter.getGlobalBounds().height / 2 - counter.getGlobalBounds().height / 3 });
		clock.restart();

		if (counterNumber == 0)
		{
			start = true;
		}
	}
}

void StartState::Update()
{
}

void StartState::Draw()
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	if (!start)
	{
		data->window.draw(counter);
	}
	data->window.draw(data->name);

	data->window.display();
}