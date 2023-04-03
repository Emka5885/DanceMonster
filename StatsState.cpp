#include "StatsState.h"
#include "MainMenuState.h"

StatsState::StatsState(GameDataReference data) : data(data)
{
}

void StatsState::Init()
{
	buttonSize = { 150, 85 };
	data->buttons->NewButton(buttonSize, { 50, 50 }, sf::Color::White, "Back", 50, sf::Color::Black, 12, 12, "back_button");
	backButton = data->buttons->GetButton("back_button").first;
	backText = data->buttons->GetButton("back_button").second;

	line.setSize({ WIDTH / 2, 50 });
	line.setPosition({ WIDTH/4, 200 });
	line.setFillColor(sf::Color::White);
	line.setOutlineThickness(4);
	line.setOutlineColor(sf::Color::Black);

	lineText.setFont(data->assets.GetFont("standardFont"));
	lineText.setCharacterSize(40);
	lineText.setString("score: 10   -   time: 135");   //later add downloading data from a file
	float margin = (float(line.getSize().x) - float(lineText.getLocalBounds().width)) / 2;
	lineText.setPosition({ WIDTH/4 + margin, 200 });
	lineText.setFillColor(sf::Color::Black);
}

void StatsState::HandleInput()
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

		if (data->input.isButtonClicked(backButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
	}
}

void StatsState::Update(float dt)
{
	
}

void StatsState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(backButton);
	data->window.draw(backText);
	data->window.draw(line);
	data->window.draw(lineText);

	data->window.display();
}
