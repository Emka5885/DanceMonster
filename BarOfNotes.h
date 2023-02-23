#pragma once

#include "Note.h"

class BarOfNotes
{
private:
	std::vector<sf::RectangleShape> bar;

public:
	BarOfNotes(float width, float height);

	void DrawBar(sf::RenderWindow& window);
};