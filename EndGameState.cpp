#include "EndGameState.h"
#include "MainMenuState.h"
#include "StatsState.h"
#include "StartState.h"

EndGameState::EndGameState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic, int combo, bool onMaxCombo) : data(data), menuSound(menuSound), backgroundMusic(backgroundMusic), combo(combo), onMaxCombo(onMaxCombo)
{
	monster = new Monster(data->assets);
	combos = new Combo(data->assets, monster);
}

void EndGameState::Init()
{
	invisible.setFillColor(sf::Color(0x1A1A1Aff));
	invisible.setPosition({ 400, 200 });
	invisible.setSize({ 400,400 });

	data->widgets->SetScorePosition({ leftText, (HEIGHT / 2) + 40 - (data->widgets->GetScoreGlobalBounds().height / 2) });
	comboText = data->widgets->GetScoreText();
	comboText.setPosition({ rightText, (HEIGHT / 2) + 140 - (data->widgets->GetScoreGlobalBounds().height / 2) });
	comboText.setString("max combo: " + std::to_string(combo));

	buttonSize = { 175, 85 };
	data->buttons->NewButton(buttonSize, { 50, HEIGHT - 50 - buttonSize.y }, sf::Color::White, "Menu", 50, sf::Color::Black, "menu_button");
	menuButton = data->buttons->GetButton("menu_button").first;
	menuText = data->buttons->GetButton("menu_button").second;

	statsButton = data->buttons->GetButton("stats_button").first;
	statsText = data->buttons->GetButton("stats_button").second;
	statsButton.setSize(buttonSize);
	statsButton.setPosition({ WIDTH - 50 - statsButton.getGlobalBounds().width, HEIGHT - 50 - statsButton.getGlobalBounds().height });
	statsText.setPosition(statsButton.getPosition().x + 15, statsButton.getPosition().y + 10);

	newGameButton = data->buttons->GetButton("play_button").first;
	newGameText = data->buttons->GetButton("play_button").second;
	newGameButton.setSize({ newGameButton.getSize().x - 100, newGameButton.getSize().y });
	newGameButton.setPosition({ newGameButton.getPosition().x + 50, newGameButton.getPosition().y + 20 });
	newGameText.setPosition({ newGameText.getPosition().x, newGameText.getPosition().y + 20 });

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
			menuSound->play();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data, menuSound, backgroundMusic)), true);
		}
		else if (data->input.isButtonClicked(statsButton, sf::Mouse::Left, data->window))
		{
			menuSound->play();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StatsState(data, menuSound, backgroundMusic)), true);
		}
		else if (data->input.isButtonClicked(newGameButton, sf::Mouse::Left, data->window))
		{
			menuSound->play();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new StartState(data, menuSound, backgroundMusic)), true, true);
		}
	}
}

void EndGameState::Update(float dt)
{
	if (leftText < (WIDTH / 2) - (data->widgets->GetScoreGlobalBounds().width / 2))
	{
		leftText += 3;
		data->widgets->SetScorePosition({ leftText, (HEIGHT / 2) + 40 - (data->widgets->GetScoreGlobalBounds().height / 2) });
	}
	if (rightText > WIDTH - (WIDTH / 2) - comboText.getGlobalBounds().width / 2)
	{
		rightText -= 3;
		comboText.setPosition({ rightText, (HEIGHT / 2) + 140 - (data->widgets->GetScoreGlobalBounds().height / 2) });
	}

	if (start)
	{
		start = false;
		monster->Start();
		frameClock.restart();
	}

	if (frameClock.getElapsedTime() >= sf::seconds(0.3) && !monster->stop)
	{
		monster->Update();
		frameClock.restart();
	}
	combos->UpdateMonsters(true);
}

void EndGameState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	monster->DrawMonster(data->window);
	data->window.draw(invisible);
	combos->DrawMonsters(data->window);
	data->widgets->DrawScore(data->window);
	if (onMaxCombo)
	{
		data->window.draw(comboText);
	}
	data->window.draw(statsButton);
	data->window.draw(statsText);
	data->window.draw(menuButton);
	data->window.draw(menuText);
	data->window.draw(newGameButton);
	data->window.draw(newGameText);
	data->window.draw(data->name);

	data->window.display();
}
