#include "Monster.h"

Monster::Monster(AssetManager& assetManager) : assetManager(assetManager)
{
	currentType = LEFT;
	currentFrame = 0;
	body.setSize({153, 153});
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition({ WIDTH / 2, HEIGHT / 2 - 50 });
	body.setTexture(&this->assetManager.GetTexture("monster"));
}

void Monster::DrawMonster(sf::RenderWindow& window)
{
	window.draw(body);
}

void Monster::Update(std::string type)
{
	if (type == currentType)
	{
		animation.ChangeFrame(currentType, currentFrame, assetManager, body);
	}
}
