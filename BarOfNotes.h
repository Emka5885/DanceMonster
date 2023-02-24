#pragma once

#include "Note.h"

class BarOfNotes
{
private:
	std::vector<sf::RectangleShape> bar;
	std::vector<Note> notes;
	sf::RenderWindow& window;
	AssetManager& assetManager;
	sf::Clock clock;

public:
	BarOfNotes(float width, float height, sf::RenderWindow& window, AssetManager& assetManager);

	void DrawBar();
	void NewNote();
	void Update();
};