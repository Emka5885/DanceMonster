#pragma once

#include <iostream>
#include <vector>
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
	bool CheckType(std::string type);
	float GetSizeX();
	void t();
	void s();
};