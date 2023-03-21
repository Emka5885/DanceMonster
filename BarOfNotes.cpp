#include "BarOfNotes.h"

BarOfNotes::BarOfNotes(sf::RenderWindow& window, AssetManager& assetManager) : window(window), assetManager(assetManager)
{
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

void BarOfNotes::NewNote()
{
	Note n(assetManager);
	notes.push_back(n);
}

void BarOfNotes::Update(float dt, bool& fail)
{
	if (!stop)
	{
		if (notes.back().PositionX() <= 1050)
		{
			NewNote();
		}
	}
	if (notes[0].PositionX() <= -100 && !notes.empty())
	{
		notes.erase(notes.begin());
	}
	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].NoteMove({ dt * -speed, 0.0f });

		if (notes[i].PositionX() <= 500 && !notes[i].isChecked)
		{
			notes[i].isChecked = true;
			//fail = true;
		}
	}
}

bool BarOfNotes::Check(std::string noteType)
{
	for (int i = 0; i < notes.size(); i++)
	{
		notes[i].s();
		if (notes[i].PositionX()-notes[i].GetSizeX()/2 >= bar[bar.size() - 2].getPosition().x && notes[i].PositionX() <= bar.back().getPosition().x - notes[i].GetSizeX()/2 + bar.back().getSize().x)
		{
			if (notes[i].CheckType(noteType))
			{
				notes[i].t();
				return true;
			}
		}
	}
	return false;
}

void BarOfNotes::ChangeSpeed(int newSpeed)
{
	speed = newSpeed;
}
