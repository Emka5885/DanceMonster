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

	note.setSize({ 100, 100 });
	note.setPosition(1200, 650);
	note.setTexture(&assetManager.GetTexture(noteType));
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

