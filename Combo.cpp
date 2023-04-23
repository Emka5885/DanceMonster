#include "Combo.h"

Combo::Combo(AssetManager& assetManage, Monster* mainMonster) : assetManager(assetManager), mainMonster(mainMonster)
{
	comboTime = false;
	mainShape.setFillColor(sf::Color(25, 50, 200, 100));
	mainShape.setRadius(500);
	mainShape.setPointCount(3);
	mainShape.setPosition( 100, -150 );

	leftX = -100;
	rightX = 1300;
	moveClock.restart();
}

void Combo::ChangeColors()
{
	if (mainShape.getFillColor() == sf::Color(25, 50, 200, 100))
	{
		mainShape.setFillColor(sf::Color(255, 0, 0, 100));
	}
	else if (mainShape.getFillColor() == sf::Color(255, 0, 0, 100))
	{
		mainShape.setFillColor(sf::Color(0, 255, 0, 100));
	}
	else if (mainShape.getFillColor() == sf::Color(0, 255, 0, 100))
	{
		mainShape.setFillColor(sf::Color(255, 255, 0, 100));
	}
	else
	{
		mainShape.setFillColor(sf::Color(25, 50, 200, 100));
	}
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

void Combo::DrawColors(sf::RenderWindow& window)
{
	//window.draw(mainShape);
}

void Combo::DrawMonsters(sf::RenderWindow& window)
{
	//UpdateMonsters(true);   //transfer later to GameState.cpp

	window.draw(leftMonster);
	window.draw(rightMonster);
}