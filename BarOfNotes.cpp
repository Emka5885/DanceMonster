#include "BarOfNotes.h"

BarOfNotes::BarOfNotes(float width, float height, sf::RenderWindow& window, AssetManager& assetManager) : window(window), assetManager(assetManager)
{
	sf::RectangleShape rect;
	rect.setSize({ width, 120 });
	rect.setPosition(0, height - 160);
	rect.setFillColor(sf::Color::Black);
	bar.push_back(rect);
	rect.setSize({ width, 100 });
	rect.setPosition(0, height - 150);
	rect.setFillColor(sf::Color::White);
	bar.push_back(rect);
	rect.setSize({ 10, 100 });
	rect.setPosition(width/2 - 75, height - 150);
	rect.setFillColor(sf::Color::Black);
	bar.push_back(rect);
	rect.setPosition(width/2 + 65, height - 150);
	bar.push_back(rect);

	NewNote();
}

void BarOfNotes::DrawBar()
{
	for (int i = 0; i < bar.size(); i++)
	{
		window.draw(bar[i]);
	}
	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].DrawArrow(window);
	}
}

void BarOfNotes::NewNote()
{
	Note n(assetManager);
	notes.push_back(n);
}

void BarOfNotes::Update(float dt)
{
	if (notes.back().PositionX() <= 1050)
	{
		NewNote();
	}
	if (notes[0].PositionX() <= -100)
	{
		notes.erase(notes.begin());
	}
	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].NoteMove({ dt * -SPEED, 0.0f });
	}
}
