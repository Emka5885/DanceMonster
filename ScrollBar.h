#pragma once
#include "AssetManager.h"

class ScrollBar
{
private:
	sf::RectangleShape scrollbarBackground;
	sf::RectangleShape scrollbarHandle;

	float maxHandleOffset;
	float scrollAmount;
	float currentHandleOffset;
	float newHandleOffset;
	float handleHight;

public:

	ScrollBar(sf::Vector2f position, float height, int howManyOptions, sf::Color backgroundColor, sf::Color handleColor);

	void Update(sf::Event event, int& counter, int maxCounter, int minCounter);

	void Draw(sf::RenderWindow& window);
};