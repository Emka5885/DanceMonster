#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Note
{
private:
	std::string noteType;
	sf::RectangleShape note;

public:
	Note(Resources& resources);

	void DrawArrow(sf::RenderWindow& window);
};