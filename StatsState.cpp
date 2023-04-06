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
	
	statsText.setString("STATS");
	statsText.setFont(data->assets.GetFont("standardFont"));
	statsText.setCharacterSize(80);
	statsText.setPosition({ 482, 40 });
	statsText.setOutlineColor(sf::Color::Black);
	statsText.setOutlineThickness(4);

	line.setSize({ WIDTH / 2, 50 });
	line.setFillColor(sf::Color(0x9e9e9eff));
	line.setOutlineThickness(4);
	line.setOutlineColor(sf::Color::Black);
	line.setPosition(WIDTH / 4, 165);

	lineText.dash.setFont(data->assets.GetFont("standardFont"));
	lineText.dash.setCharacterSize(40);
	lineText.dash.setFillColor(sf::Color::Black);
	lineText.dash.setString("-");
	lineText.dash.setPosition({ WIDTH / 2 - 2, 165 });

	lineText.scoreText.setFont(data->assets.GetFont("standardFont"));
	lineText.scoreText.setCharacterSize(40);
	lineText.scoreText.setFillColor(sf::Color::Black);
	lineText.scoreText.setString("score:");
	margin = (float(line.getSize().x / 2) - float(lineText.scoreText.getLocalBounds().width)) / 2;
	lineText.scoreText.setPosition({ WIDTH / 4 + margin, 165 });

	lineText.timeText.setFont(data->assets.GetFont("standardFont"));
	lineText.timeText.setCharacterSize(40);
	lineText.timeText.setFillColor(sf::Color::Black);
	lineText.timeText.setString("time:");
	margin = (float(line.getSize().x / 2) - float(lineText.timeText.getLocalBounds().width)) / 2;
	lineText.timeText.setPosition({ WIDTH / 2 + margin, 165 });

	statsLines.push_back(std::pair<sf::RectangleShape, Texts>());
	statsLines.back().first = line;
	statsLines.back().second = lineText;


	line.setFillColor(sf::Color::White);

	std::fstream file;
	file.open("stats.txt");
	if (file.is_open())
	{
		std::string helperLine;
		while (std::getline(file, helperLine))
		{
			statsLinesText.push_back(helperLine);
			counterLine += 50;
		}

		file.close();
	}

	int i = 0;
	while (counterLine > 0)
	{
		counterLine -= 50;
		line.setPosition(WIDTH / 4, 225 + counterLine);

		std::string helper = statsLinesText[i];
		std::string sText, tText;
		bool dash = false;
		for (int j = 0; j < helper.size(); j++)
		{
			if (helper[j] == '-')
			{
				dash = true;
			}
			else
			{
				if (dash)
				{
					tText += helper[j];
				}
				else
				{
					sText += helper[j];
				}
			}
		}
		lineText.scoreText.setString(sText);
		lineText.timeText.setString(tText);

		lineText.dash.setPosition({ WIDTH / 2 - 2, 225 + counterLine });
		margin = (float(line.getSize().x / 2) - float(lineText.scoreText.getLocalBounds().width)) / 2;
		lineText.scoreText.setPosition({ WIDTH / 4 + margin, 225 + counterLine });
		margin = (float(line.getSize().x / 2) - float(lineText.timeText.getLocalBounds().width)) / 2;
		lineText.timeText.setPosition({ WIDTH / 2 + margin, 225 + counterLine });

		statsLines.push_back(std::pair<sf::RectangleShape, Texts>());
		statsLines.back().first = line;
		statsLines.back().second = lineText;

		i++;
	}

	if (i > 10)
	{
		scrollBar = new ScrollBar({ WIDTH / 1.30, 223 }, int(504 / (i-9)) * (i-9), i - 9, sf::Color::Black, sf::Color(0x9e9e9eff));
		checkCounter = true;
	}
	else
	{
		scrollBar = new ScrollBar({ WIDTH / 1.30, 223 }, 504, 1, sf::Color::Black, sf::Color(0x9e9e9eff));
		checkCounter = false;
	}
	counter = statsLines.size() - 1;
}

void StatsState::HandleInput()
{
	int oldCounter = counter;

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

		if (checkCounter)
		{
			scrollBar->Update(event, counter, statsLines.size() - 1, 10);
		}
	}

	if (counter != oldCounter)
	{
		Update(0);
	}
}

void StatsState::Update(float dt)
{
	int j = 0;
	for (int i = counter; i >= counter - 10; i--)
	{
		if (i < 1)
		{
			break;
		}
		statsLines[i].first.setPosition(statsLines[i].first.getPosition().x, 225 + j * 50);
		statsLines[i].second.scoreText.setPosition(statsLines[i].second.scoreText.getPosition().x, 225 + j * 50);
		statsLines[i].second.dash.setPosition(statsLines[i].second.dash.getPosition().x, 225 + j * 50);
		statsLines[i].second.timeText.setPosition(statsLines[i].second.timeText.getPosition().x, 225 + j * 50);

		j++;
	}
}

void StatsState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(backButton);
	data->window.draw(backText);
	data->window.draw(statsText);

	data->window.draw(statsLines[0].first);
	data->window.draw(statsLines[0].second.scoreText);
	data->window.draw(statsLines[0].second.dash);
	data->window.draw(statsLines[0].second.timeText);

	for (int i = counter; i >= counter-9; i--)
	{
		if (i < 1)
		{
			break;
		}
		data->window.draw(statsLines[i].first);
		data->window.draw(statsLines[i].second.scoreText);
		data->window.draw(statsLines[i].second.dash);
		data->window.draw(statsLines[i].second.timeText);
	}

	scrollBar->Draw(data->window);

	data->window.display();
}
