#include "Game.h"
#include "MainMenuState.h"

Game::Game(std::string title)
{
	data->widgets = new Widgets(data->assets);
	data->buttons = new Buttons(data->assets);
	srand(time(NULL));
	data->window.create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Close | sf::Style::Titlebar);
	data->machine.AddState(stateReference(new MainMenuState(data, &menuSound, &backgroundMusic)), true);
	this->Run();
}

void Game::Run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->data->window.isOpen())
	{
		this->data->machine.ProcessStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->data->machine.GetActiveState()->HandleInput();

			if (!this->data->window.isOpen())
			{
				return;
			}

			this->data->machine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		this->data->machine.GetActiveState()->Draw(interpolation);

		if (startBackgroundMusic && this->data->machine.hasMenuBackgroundMusic())
		{
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
				}
				file.close();
			}

			if (!backgroundMusic.openFromFile("resources/music/menu-53679.wav"))
			{
				std::cout << "Error - menu background music" << std::endl;
			}
			backgroundMusic.setLoop(true);
			backgroundMusic.setVolume(musicOptionsFromFile[1]);
			backgroundMusic.play();

			if (!menuSoundBuffer.loadFromFile("resources/sounds/menu-button.wav"))
			{
				std::cout << "Error sound - menu button" << std::endl;
			}
			menuSound.setBuffer(menuSoundBuffer);
			menuSound.setVolume(musicOptionsFromFile[0]);

			startBackgroundMusic = false;
		}
		else if (!this->data->machine.hasMenuBackgroundMusic())
		{
			backgroundMusic.stop();
			startBackgroundMusic = true;
		}
	}
}
