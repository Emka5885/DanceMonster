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

	std::string type;

	sf::RenderWindow& window;

	bool isDragging;
	sf::Vector2f dragOffset;

public:

	ScrollBar(sf::Vector2f position, float height, int howManyOptions, sf::Color backgroundColor, sf::Color handleColor, std::string type, sf::RenderWindow& window);

	void Update(sf::Event event, int& counter, int maxCounter, int minCounter);

	void Draw();
};