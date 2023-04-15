#include "EndGameState.h"
#include "MainMenuState.h"
#include "StatsState.h"

EndGameState::EndGameState(GameDataReference data) : data(data)
{
}

void EndGameState::Init()
{
	data->widgets->SetScorePosition({ (WIDTH / 2) - (data->widgets->GetScoreGlobalBounds().width / 2), (HEIGHT / 2) - (data->widgets->GetScoreGlobalBounds().height / 2) });

	//statsButton = data->buttons->GetButton("stats_button").first;
	//statsText = data->buttons->GetButton("stats_button").second;

	buttonSize = { 175, 85 };
	data->buttons->NewButton(buttonSize, { 50, HEIGHT - 50 - buttonSize.y }, sf::Color::White, "Menu", 50, sf::Color::Black, "menu_button");
	menuButton = data->buttons->GetButton("menu_button").first;
	menuText = data->buttons->GetButton("menu_button").second;

	std::fstream file;
	std::string line;
	line = "" + std::to_string(data->widgets->GetScore()) + "-" + std::to_string(data->widgets->GetTime());
	file.open("stats.txt", std::fstream::app);
	file << line << "\n";
	
	file.close();
}

void EndGameState::HandleInput()
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

		if (data->input.isButtonClicked(menuButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
		/*else if (data->input.isButtonClicked(statsButton, sf::Mouse::Left, data->window))
		{
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StatsState(data)), true);
		}*/
	}
}

void EndGameState::Update(float dt)
{
}

void EndGameState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->widgets->DrawScore(data->window);
	//data->window.draw(statsButton);
	//data->window.draw(statsText);

	data->window.draw(menuButton);
	data->window.draw(menuText);

	data->window.display();
}
