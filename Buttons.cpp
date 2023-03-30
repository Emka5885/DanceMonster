#include "Buttons.h"

Buttons::Buttons(AssetManager& assetManager) : assetManager(assetManager)
{
	buttonText.setFont(assetManager.GetFont("standardFont"));

}

void Buttons::NewButton(sf::Vector2f size, sf::Vector2f position, sf::Color buttonColor, std::string text, int characterSize, sf::Color textColor, std::string buttonName)
{
	newButton.setSize(size);
	newButton.setPosition(position);
	newButton.setFillColor(buttonColor);

	buttonText.setPosition({ position.x + 12, position.y + 12 });
	buttonText.setCharacterSize(characterSize);
	buttonText.setString(text);
	buttonText.setFillColor(textColor);

	button.first = newButton;
	button.second = buttonText;
	this->buttons[buttonName] = button;
}

std::pair<sf::RectangleShape, sf::Text> Buttons::GetButton(std::string buttonName)
{
	return buttons[buttonName];
}
