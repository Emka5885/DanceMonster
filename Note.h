#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"

class Note
{
private:
	std::string noteType;
	sf::RectangleShape note;

public:
	Note(AssetManager& assetManager);

	void DrawArrow(sf::RenderWindow& window);
	float PositionX();
	void NoteMove(sf::Vector2f move);
};