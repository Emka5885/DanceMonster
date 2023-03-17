#pragma once
#include "AssetManager.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

	sf::Vector2i GetMousePosition(sf::RenderWindow& window);

	std::string checkArrow(sf::Keyboard::Key button);
};