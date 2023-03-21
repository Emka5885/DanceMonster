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
		note.setSize({ 60, 104 });
	}
	else
	{
		note.setSize({ 104, 104 });
	}
	note.setPosition(1250, 650);
	note.setTexture(&assetManager.GetTexture(noteType));
	note.setOrigin(note.getSize().x / 2, 0);

	isChecked = false;
}

void Note::DrawArrow(sf::RenderWindow& window)
{
	window.draw(note);
}

float Note::PositionX()
{
	return note.getPosition().x;
}

void Note::NoteMove(sf::Vector2f move)
{
	note.move(move);
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

void Note::t()
{
	note.setFillColor(sf::Color::Green);
}

void Note::s()
{
	note.setFillColor(sf::Color::White);
}

