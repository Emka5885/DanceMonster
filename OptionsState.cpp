#include "OptionsState.h"
#include "MainMenuState.h"

OptionsState::OptionsState(GameDataReference data, sf::Sound* menuSound, sf::Music* backgroundMusic) : data(data), menuSound(menuSound), backgroundMusic(backgroundMusic)
{
	s = nullptr;
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
		}

		file.close();
	}
}

void OptionsState::Init()
{
	std::fstream file;
	file.open("musicOptions.txt", std::ios::in);
	if (file.is_open())
	{
		std::string helperLine;
		while (file >> helperLine)
		{
			if (std::isdigit(helperLine[0]))
			{
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
			menuSound->play();
			Save();
			data->machine.RemoveState();
			data->machine.AddState(stateReference(new MainMenuState(data, menuSound, backgroundMusic)), true);
		}

		for (int i = 0; i < OnOffButtons.size(); i++)
		{
			if (data->input.isButtonClicked(OnOffButtons[i].first.first, sf::Mouse::Left, data->window))
			{
				menuSound->play();
				OnOffButtons[i].first.first.setFillColor(sf::Color(0x9e9e9eff));
				OnOffButtons[i].second.first.setFillColor(sf::Color::White);
				optionsFromFile[i] = true;
			}
			else if (data->input.isButtonClicked(OnOffButtons[i].second.first, sf::Mouse::Left, data->window))
			{
				menuSound->play();
				OnOffButtons[i].first.first.setFillColor(sf::Color::White);
				OnOffButtons[i].second.first.setFillColor(sf::Color(0x9e9e9eff));
				optionsFromFile[i] = false;
			}
		}
	}
	for (int i = 0; i < scrollBars.size(); i++)
	{
		scrollBars[i].Update(event, 50, 1);
	}
	menuSound->setVolume(musicOptionsFromFile[0]);
	backgroundMusic->setVolume(musicOptionsFromFile[1]);
}

void OptionsState::Update()
{
}

void OptionsState::Draw()
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
	for (int i = 0; i < OnOffButtons.size(); i++)
	{
		data->window.draw(OnOffButtons[i].first.first);
		data->window.draw(OnOffButtons[i].first.second);
		data->window.draw(OnOffButtons[i].second.first);
		data->window.draw(OnOffButtons[i].second.second);
	}
	data->window.draw(data->name);

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

	onShape.setOutlineColor(sf::Color::Black);
	onShape.setOutlineThickness(2);
	onShape.setSize({ WIDTH / 10, 30 });
	offShape = onShape;
	onShape.setPosition({ WIDTH / 2 + 25, 643 });
	offShape.setPosition({ WIDTH / 2 + WIDTH / 8 - 2, 643 });

	if (optionsFromFile[0])
	{
		onShape.setFillColor(sf::Color(0x9e9e9eff));
		offShape.setFillColor(sf::Color::White);
	}
	else
	{
		onShape.setFillColor(sf::Color::White);
		offShape.setFillColor(sf::Color(0x9e9e9eff));
	}

	onText.setFont(data->assets.GetFont("standardFont"));
	onText.setCharacterSize(25);
	onText.setFillColor(sf::Color::Black);
	offText = onText;
	onText.setString("On");
	onText.setPosition({ WIDTH / 2 + 25 + ((float(onShape.getSize().x) - float(onText.getLocalBounds().width)) / 2), onShape.getPosition().y });
	offText.setString("Off");
	offText.setPosition({ WIDTH / 2 + WIDTH / 8 - 2 + ((float(offShape.getSize().x) - float(offText.getLocalBounds().width)) / 2), offShape.getPosition().y });

	MusicOptionsPushBack(false);
	OptionsPushBack();

	shape.setPosition(WIDTH / 4, 685);

	text.setString("combo counter:");
	text.setPosition({ WIDTH / 4 + 10, 695 });

	onShape.setPosition({ WIDTH / 2 + 25, 693 });
	offShape.setPosition({ WIDTH / 2 + WIDTH / 8 - 2, 693 });

	if (optionsFromFile[1])
	{
		onShape.setFillColor(sf::Color(0x9e9e9eff));
		offShape.setFillColor(sf::Color::White);
	}
	else
	{
		onShape.setFillColor(sf::Color::White);
		offShape.setFillColor(sf::Color(0x9e9e9eff));
	}

	onText.setPosition({ WIDTH / 2 + 25 + ((float(onShape.getSize().x) - float(onText.getLocalBounds().width)) / 2), onShape.getPosition().y });
	offText.setPosition({ WIDTH / 2 + WIDTH / 8 - 2 + ((float(offShape.getSize().x) - float(offText.getLocalBounds().width)) / 2), offShape.getPosition().y });

	MusicOptionsPushBack(false);
	OptionsPushBack();
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

void OptionsState::OptionsPushBack()
{
	OnOffButtons.push_back(helper2);
	OnOffButtons.back().first.first = onShape;
	OnOffButtons.back().first.second = onText;
	OnOffButtons.back().second.first = offShape;
	OnOffButtons.back().second.second = offText;
}
