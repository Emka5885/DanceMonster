#pragma once
#include "AssetManager.h"

class Buttons
{
private:
	AssetManager& assetManager;

	sf::RectangleShape newButton;
	sf::Text buttonText;

	sf::Font font;
	std::pair<sf::RectangleShape, sf::Text> button;

public:
	Buttons(AssetManager& assetManager);

	void NewButton(sf::Vector2f size, sf::Vector2f position, sf::Color buttonColor, std::string text, int characterSize, sf::Color textColor, std::string buttonName);
	std::pair<sf::RectangleShape, sf::Text> GetButton(std::string buttonName);

	std::map<std::string, std::pair<sf::RectangleShape, sf::Text>> buttons;
};
