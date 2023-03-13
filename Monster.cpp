#include "Monster.h"
#include <iostream>

Monster::Monster(AssetManager& assetManager) : assetManager(assetManager)
{
	currentType = NORMAL;
	changeType = false;
	error = false;
	counter = 0;
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

void Monster::Update()
{
	if (!changeType && !error)
	{
		std::cout << "d" << "\n";
		animation.ChangeFrame(currentType, currentFrame, assetManager, body, changeType);
	}
	else if(changeType && !error)
	{
		if (counter == randomNumber)
		{
			if (currentFrame != 6)
			{
				random = rand() % 4;
			}
			switch (random)
			{
			case 0:
				animation.ChangeType(currentType, LEFT, currentFrame, assetManager, body, changeType, randomNumber);
				break;
			case 1:
				animation.ChangeType(currentType, RIGHT, currentFrame, assetManager, body, changeType, randomNumber);
				break;
			case 2:
				animation.ChangeType(currentType, UP, currentFrame, assetManager, body, changeType, randomNumber);
				break;
			case 3:
				animation.ChangeType(currentType, DOWN, currentFrame, assetManager, body, changeType, randomNumber);
				break;
			}
			
			if (currentFrame == 0)
			{
				counter = 0;
			}
		}
		else
		{
			if (currentFrame == 1)
			{
				counter++;
			}
		}
	}
}

void Monster::Error(bool isWrong)
{
	if (isWrong)
	{
		body.setTexture(&this->assetManager.GetTexture("monster_error"));
		error = true;
	}
	else
	{
		error = false;
	}
}

void Monster::Start()
{
	changeType = true;
}
