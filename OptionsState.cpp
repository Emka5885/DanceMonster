#include "OptionsState.h"
#include "MainMenuState.h"

OptionsState::OptionsState(GameDataReference data) : data(data)
{
}

void OptionsState::Save()
{
	std::fstream file;
	file.open("musicOptions.txt", std::ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			file << musicOptionsFromFile[i] << "\n";
			//std::cout << "d" << musicOptionsFromFile[i];
		}
		for (int i = 0; i < 2; i++)
		{
			if (optionsFromFile[i])
			{
				file << "true\n";
			}
			else
			{
				file << "false\n";
			}
			//std::cout << "d" << musicOptionsFromFile[i];
		}

		file.close();
	}
}

void OptionsState::Init()
{
	//std::cout << "dziala\n";
	std::fstream file;
	file.open("musicOptions.txt", std::ios::in);
	if (file.is_open())
	{
		std::string helperLine;
		while (file >> helperLine)
		{
			if (std::isdigit(helperLine[0]))
			{
				//std::cout << helperLine << "\n";
				musicOptionsFromFile.push_back(std::stoi(helperLine));
			}
			else if (helperLine == "true")
			{
				optionsFromFile.push_back(true);
			}
			else if (helperLine == "false")
			{
				optionsFromFile.push_back(false);
			}
		}
		file.close();
	}

	/*for (int i = 0; i < 5; i++)
	{
		std::cout << "e " << musicOptionsFromFile[i];
	}*/

	buttonSize = { 150, 85 };
	data->buttons->NewButton(buttonSize, { 50, 50 }, sf::Color::White, "Back", 50, sf::Color::Black, "back_button");
	backButton = data->buttons->GetButton("back_button").first;
	backText = data->buttons->GetButton("back_button").second;

	optionsText.setString("OPTIONS");
	optionsText.setFont(data->assets.GetFont("standardFont"));
	optionsText.setCharacterSize(80);
	optionsText.setOutlineColor(sf::Color::Black);
	optionsText.setOutlineThickness(4);
	optionsText.setPosition({ WIDTH / 2 - optionsText.getGlobalBounds().width / 2, 50});

	CreateMusicOptionsButtons();
}

void OptionsState::HandleInput()
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
	for (int i = 0; i < scrollBars.size(); i++)
	{
		scrollBars[i].Update(event, 50, 1);
	}
}

void OptionsState::Update(float dt)
{
}

void OptionsState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	data->window.draw(backButton);
	data->window.draw(backText);
	data->window.draw(optionsText);

	int j = 0;
	for (int i = 0; i < options.size(); i++)
	{
		data->window.draw(options[i].first.first);
		data->window.draw(options[i].first.second);
		if (options[i].second)
		{
			scrollBars[j].Draw();
			j++;
		}
	}

	data->window.display();
}

void OptionsState::CreateMusicOptionsButtons()
{
	shape.setSize({ WIDTH / 2, 50 });
	shape.setFillColor(sf::Color(0x9e9e9eff));
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color::Black);
	shape.setPosition(WIDTH / 4, 175);

	text.setFont(data->assets.GetFont("standardFont"));
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setString("audio - menu:");
	text.setPosition({ WIDTH / 4 + 10, 175 });

	MusicOptionsPushBack(false);


	shape.setFillColor(sf::Color::White);
	shape.setPosition(WIDTH / 4, 235);

	text.setString("button sound:");
	text.setCharacterSize(30);
	text.setPosition({ WIDTH / 4 + 10, 245 });

	s = new ScrollBar({ WIDTH / 2 + 25, 260 }, WIDTH / 5, 50, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[0]);

	MusicOptionsPushBack(true);

	shape.setPosition(WIDTH / 4, 285);

	text.setString("background music:");
	text.setPosition({ WIDTH / 4 + 10, 295 });

	s = new ScrollBar({ WIDTH / 2 + 25, 310 }, WIDTH / 5, 50, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[1]);

	MusicOptionsPushBack(true);



	shape.setFillColor(sf::Color(0x9e9e9eff));
	shape.setPosition(WIDTH / 4, 350);

	text.setCharacterSize(40);
	text.setString("audio - game:");
	text.setPosition({ WIDTH / 4 + 10, 350 });

	MusicOptionsPushBack(false);


	shape.setFillColor(sf::Color::White);
	shape.setPosition(WIDTH / 4, 410);

	text.setString("error sound:");
	text.setCharacterSize(30);
	text.setPosition({ WIDTH / 4 + 10, 420 });

	s = new ScrollBar({ WIDTH / 2 + 25, 435 }, WIDTH / 5, 50, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[2]);

	MusicOptionsPushBack(true);

	shape.setPosition(WIDTH / 4, 460);

	text.setString("background music:");
	text.setPosition({ WIDTH / 4 + 10, 470 });

	s = new ScrollBar({ WIDTH / 2 + 25, 485 }, WIDTH / 5, 50, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[3]);

	MusicOptionsPushBack(true);

	shape.setPosition(WIDTH / 4, 510);

	text.setString("combo time:");
	text.setPosition({ WIDTH / 4 + 10, 520 });

	s = new ScrollBar({ WIDTH / 2 + 25, 535 }, WIDTH / 5, 50, sf::Color::Black, sf::Color(0x9e9e9eff), "horizontal", data->window, musicOptionsFromFile[4]);

	MusicOptionsPushBack(true);



	shape.setFillColor(sf::Color(0x9e9e9eff));
	shape.setPosition(WIDTH / 4, 575);

	text.setCharacterSize(40);
	text.setString("visual effects:");
	text.setPosition({ WIDTH / 4 + 10, 575 });

	MusicOptionsPushBack(false);


	shape.setFillColor(sf::Color::White);
	shape.setPosition(WIDTH / 4, 635);

	text.setString("combo time:");
	text.setCharacterSize(30);
	text.setPosition({ WIDTH / 4 + 10, 645 });

	MusicOptionsPushBack(false);

	shape.setPosition(WIDTH / 4, 685);

	text.setString("combo counter:");
	text.setPosition({ WIDTH / 4 + 10, 695 });

	MusicOptionsPushBack(false);
}

void OptionsState::MusicOptionsPushBack(bool ScrollBar)
{
	options.push_back(helper);
	options.back().first.first = shape;
	options.back().first.second = text;
	options.back().second = ScrollBar;

	if (ScrollBar)
	{
		scrollBars.push_back(*s);
	}
}
