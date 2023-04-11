#include "MusicState.h"
#include "MainMenuState.h"

MusicState::MusicState(GameDataReference data) : data(data)
{
}

void MusicState::Save()
{
	std::fstream file;
	file.open("musicOptions.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			file << musicOptionsFromFile[i] << "\n";
			//std::cout << "d" << musicOptionsFromFile[i];
		}

		file.close();
	}
}

void MusicState::Init()
{
	std::cout << "dziala\n";
	std::fstream file;
	file.open("musicOptions.txt");
	if (file.is_open())
	{
		std::string helperLine;
		while (file >> helperLine)
		{
			if (!helperLine.empty())
			{
				//std::cout << helperLine << "\n";
				musicOptionsFromFile.push_back(std::stoi(helperLine));
			}
		}
		file.close();
	}

	buttonSize = { 150, 85 };
	data->buttons->NewButton(buttonSize, { 50, 50 }, sf::Color::White, "Back", 50, sf::Color::Black, "back_button");
	backButton = data->buttons->GetButton("back_button").first;
	backText = data->buttons->GetButton("back_button").second;

	musicText.setString("MUSIC");
	musicText.setFont(data->assets.GetFont("standardFont"));
	musicText.setCharacterSize(80);
	musicText.setOutlineColor(sf::Color::Black);
	musicText.setOutlineThickness(4);
	musicText.setPosition({ WIDTH / 2 - musicText.getGlobalBounds().width / 2, 50});

	CreateMusicOptionsButtons();
}

void MusicState::HandleInput()
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
			Save();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data)), true);
		}
	}
	for (int i = 0; i < musicScrollBars.size(); i++)
	{
		musicScrollBars[i].Update(event, 51, 1);
	}
}

void MusicState::Update(float dt)
{
}

void MusicState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(backButton);
	data->window.draw(backText);
	data->window.draw(musicText);

	int j = 0;
	for (int i = 0; i < musicOptions.size(); i++)
	{
		data->window.draw(musicOptions[i].first.first);
		data->window.draw(musicOptions[i].first.second);
		if (musicOptions[i].second)
		{
			musicScrollBars[j].Draw();
			j++;
		}
	}

	data->window.display();
}

void MusicState::CreateMusicOptionsButtons()
{
	shape.setSize({ WIDTH / 2, 50 });
	shape.setFillColor(sf::Color(0x9e9e9eff));
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color::Black);
	shape.setPosition(WIDTH / 4, 175);

	text.setFont(data->assets.GetFont("standardFont"));
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setString("menu:");
	text.setPosition({ WIDTH / 4 + 10, 175 });

	MusicOptionsPushBack(false);



	shape.setFillColor(sf::Color::White);
	shape.setPosition(WIDTH / 4, 235);

	text.setString("button sound:");
	text.setCharacterSize(30);
	text.setPosition({ WIDTH / 4 + 10, 245 });

	s = new ScrollBar({ WIDTH / 2 + 25, 260 }, WIDTH / 5, 51, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[0]);

	MusicOptionsPushBack(true);

}

void MusicState::MusicOptionsPushBack(bool ScrollBar)
{
	musicOptions.push_back(helper);
	musicOptions.back().first.first = shape;
	musicOptions.back().first.second = text;
	musicOptions.back().second = ScrollBar;

	if (ScrollBar)
	{
		musicScrollBars.push_back(*s);
	}
}
