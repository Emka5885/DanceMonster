#include "Combo.h"

Combo::Combo(AssetManager& assetManage, Monster* mainMonster) : assetManager(assetManager), mainMonster(mainMonster)
{
	comboTime = false;

	leftX = -100;
	rightX = 1300;
	moveClock.restart();
}

void Combo::UpdateMonsters(bool isCombo)
{
	leftMonster = mainMonster->GetBody();
	leftMonster.setScale(0.6, 0.6);

	rightMonster = leftMonster;
	rightMonster.setScale(0.6, 0.6);

	if (isCombo)
	{
		if (leftX < 245 && moveClock.getElapsedTime() >= sf::seconds(0.1))
		{
			MonstersStart();
			moveClock.restart();
		}
	}
	else
	{
		if (leftX > -100 && moveClock.getElapsedTime() >= sf::seconds(0.1))
		{
			MonstersStop();
			moveClock.restart();
		}
	}

	leftMonster.setPosition(leftX, 275);
	rightMonster.setPosition(rightX, 275);
}

void Combo::MonstersStart()
{
	leftX += 12;
	rightX -= 12;
}

void Combo::MonstersStop()
{
	leftX -= 12;
	rightX += 12;
}

void Combo::DrawMonsters(sf::RenderWindow& window)
{
	window.draw(leftMonster);
	window.draw(rightMonster);
}