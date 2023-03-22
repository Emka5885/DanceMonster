#include "Note.h"

Note::Note(AssetManager& assetManager)
{
	switch (rand() % 4)
	{
	case 0:
		noteType = RIGHT;
		break;
	case 1:
		noteType = LEFT;
		break;
	case 2:
		noteType = UP;
		break;
	case 3:
		noteType = DOWN;
		break;
	}

	if (noteType == UP || noteType == DOWN)
	{
		note.setSize({ 60, 100 });
	}
	else
	{
		note.setSize({ 104, 100 });
	}
	note.setPosition(1250, 650);
	note.setOrigin(note.getSize().x / 2, 0);
	whiteShape = note;
	whiteShape.setFillColor(sf::Color(255,255,255,alpha));
	note.setTexture(&assetManager.GetTexture(noteType));

	isChecked = false;
}

void Note::DrawArrow(sf::RenderWindow& window)
{
	window.draw(note);
	window.draw(whiteShape);
}

float Note::PositionX()
{
	return note.getPosition().x;
}

void Note::NoteMove(sf::Vector2f move)
{
	note.move(move);
	whiteShape.move(move);
}

bool Note::CheckType(std::string type)
{
	if (!isChecked)
	{
		if (type == noteType)
		{
			isChecked = true;
			return true;
		}
	}
	return false;
}

float Note::GetSizeX()
{
	return note.getSize().x;
}

void Note::IncreaseWhiteShape(int howMuchToAdd)
{
	if (alpha < 255)
	{
		alpha += howMuchToAdd;
	}
	whiteShape.setFillColor(sf::Color(255, 255, 255, alpha));
}

