#include "BarOfNotes.h"

BarOfNotes::BarOfNotes(float width, float height)
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
}

void BarOfNotes::DrawBar(sf::RenderWindow& window)
{
	for (int i = 0; i < bar.size(); i++)
	{
		window.draw(bar[i]);
	}
}
