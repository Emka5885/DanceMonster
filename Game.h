#pragma once
#include <memory>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Widgets.h"
#include "Buttons.h"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
	Widgets* widgets;
	Buttons* buttons;
};

typedef std::shared_ptr<GameData> GameDataReference;

class Game
{
public:
	Game(std::string title);

private:
	std::fstream file;

	const float dt = 1.0f / 60.0f;
	sf::Clock clock;

	GameDataReference data = std::make_shared<GameData>();

	void Run();

	std::vector<int> musicOptionsFromFile;
	
	sf::SoundBuffer menuSoundBuffer;
	sf::Sound menuSound;

	sf::Music backgroundMusic;
	bool startBackgroundMusic = true;
};