#include "Combo.h"

Combo::Combo(AssetManager& assetManage) : assetManager(assetManager)
{
	mainShape.setFillColor(sf::Color(25, 50, 200, 100));
	mainShape.setRadius(500);
	mainShape.setPointCount(3);
	mainShape.setPosition( 100, -150 );
}

void Combo::DrawColors(sf::RenderWindow& window)
{
	window.draw(mainShape);
}

void Combo::ChangeMainShapeColor()
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
