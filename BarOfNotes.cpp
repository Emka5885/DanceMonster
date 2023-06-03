#include "BarOfNotes.h"

BarOfNotes::BarOfNotes(sf::RenderWindow& window, AssetManager& assetManager) : window(window), assetManager(assetManager)
{
	helper = -1;
	ChangeSpeed(200);
	stop = false;
	sf::RectangleShape rect;
	rect.setSize({ WIDTH, 120 });
	rect.setPosition(0, HEIGHT - 160);
	rect.setFillColor(sf::Color::Black);
	bar.push_back(rect);
	rect.setSize({ WIDTH, 100 });
	rect.setPosition(0, HEIGHT - 150);
	rect.setFillColor(sf::Color::White);
	bar.push_back(rect);
	rect.setSize({ 10, 100 });
	rect.setPosition(WIDTH /2 - 75, HEIGHT - 150);
	rect.setFillColor(sf::Color::Black);
	bar.push_back(rect);
	rect.setPosition(WIDTH /2 + 65, HEIGHT - 150);
	bar.push_back(rect);

	NewNote();
}

void BarOfNotes::NewNote()
{
	Note n(assetManager);
	notes.push_back(n);
}

void BarOfNotes::Update(float dt)
{
	if (!stop)
	{
		if (notes.back().PositionX() <= 1050)
		{
			NewNote();
		}
	}
	if (notes[0].PositionX() <= -speed && !notes.empty())
	{
		notes.erase(notes.begin());
		helper--;
	}

	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].NoteMove({ dt * -speed, 0.0f });
	}
}

bool BarOfNotes::Check(std::string noteType)
{
	for (int i = 0; i < notes.size(); i++)
	{
		if (notes[i].PositionX()-notes[i].GetSizeX()/2 >= bar[bar.size() - 2].getPosition().x && notes[i].PositionX() <= bar.back().getPosition().x - notes[i].GetSizeX()/2 + bar.back().getSize().x)
		{
			if (notes[i].CheckType(noteType))
			{
				if (helper < 0)
				{
					helper = i;
				}
				return true;
			}
		}
	}
	return false;
}

void BarOfNotes::IncreaseWhiteShape()
{
	if (helper >= 0)
	{
		notes[helper].IncreaseWhiteShape(howMuchToAdd);

		if (notes[helper].alpha >= 255)
		{
			notes.erase(notes.begin() + helper);
			helper = -1;
		}
	}
}

void BarOfNotes::ChangeSpeed(int newSpeed)
{
	if (newSpeed < 350)
	{
		speed = newSpeed;
		if (howMuchToAdd <= 255)
		{
			howMuchToAdd+=5;
		}
	}
}

void BarOfNotes::DrawBar()
{
	for (int i = 0; i < bar.size() - 2; i++)
	{
		window.draw(bar[i]);
	}
	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].DrawArrow(window);
	}
	for (int i = bar.size() - 2; i < bar.size(); i++)
	{
		window.draw(bar[i]);
	}
}