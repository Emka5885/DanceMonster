#include "Monster.h"

Monster::Monster(AssetManager& assetManager)
{
	totalTime = 0.0f;

	body.setSize({500, 500});
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition({ WIDTH / 2, HEIGHT / 2 - 50 });
	body.setFillColor(sf::Color::Blue);
	//body.setTexture(&assetManager.GetTexture("monster"));
}

void Monster::DrawMonster(sf::RenderWindow& window)
{
	window.draw(body);
}

void Monster::Update(std::string type)
{
}
