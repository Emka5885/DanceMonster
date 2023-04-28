#include "Game.h"
#include "MainMenuState.h"

Game::Game(std::string title) : title(title)
{
}

void Game::Init()
{
	data->widgets = new Widgets(data->assets);
	data->buttons = new Buttons(data->assets);
	srand(time(NULL));
	data->window.create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Close | sf::Style::Titlebar);
	data->window.setFramerateLimit(60);

	if (!image.loadFromFile("resources/monster/monster_icon.png"))
	{
		std::cout << "Error - icon.\n";
	}
	data->window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	data->name.setFont(data->assets.GetFont("nameFont"));
	data->name.setCharacterSize(15);
	data->name.setFillColor(sf::Color::Black);
	data->name.setString("© Emilia Masiak");
	data->name.setPosition(WIDTH - 10 - data->name.getGlobalBounds().width, HEIGHT - 10 - data->name.getGlobalBounds().height);

	data->machine.AddState(stateReference(new MainMenuState(data, &menuSound, &backgroundMusic)), true);
}


void Game::Run()
{
	float newTime, frameTime;

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

			this->data->machine.GetActiveState()->Update();

			accumulator -= dt;
		}
		this->data->machine.GetActiveState()->Draw();

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