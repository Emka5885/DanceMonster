#include "Combo.h"

Combo::Combo(AssetManager& assetManage) : assetManager(assetManager)
{
	mainShape.setFillColor(sf::Color(25, 50, 200, 100));
	mainShape.setRadius(500);
	mainShape.setPointCount(3);
	mainShape.setPosition( 100, -150 );

	leftMonster = new Monster(assetManager, false);
	//rightMonster = new Monster(assetManager);
	//MonstersStart();
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

void Combo::MonstersStart()
{
	leftMonster->ChangeScale({ 0.5, 0.5 });
	leftMonster->ChangePosition({50, 200});
}

void Combo::MonstersStop()
{
	
}

void Combo::DrawColors(sf::RenderWindow& window)
{
	window.draw(mainShape);
	//DrawMonsters(window);
}

void Combo::DrawMonsters(sf::RenderWindow& window)
{
	leftMonster->DrawMonster(window);
	//rightMonster->DrawMonster(window);
}