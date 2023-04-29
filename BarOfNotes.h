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
	int howMuchToAdd = 10;

public:
	BarOfNotes(sf::RenderWindow& window, AssetManager& assetManager);

	int helper;
	void NewNote();
	void Update(float dt, int& combo, int& counter);
	bool Check(std::string noteType);
	bool stop;
	void IncreaseWhiteShape();
	int speed;
	void ChangeSpeed(int newSpeed);
	void DrawBar();
};