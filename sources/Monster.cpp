#include "Monster.h"

Monster::Monster(AssetManager& assetManager) : assetManager(assetManager)
{
	currentType = NORMAL;
	newType = RIGHT;
	changeType = false;
	error = false;
	stop = false;
	counter = 0;
	randomNumber = 0;
	currentFrame = 0;

	body.setSize({306, 306 });
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition({ WIDTH / 2, HEIGHT / 2 - 50 });
	body.setTexture(assetManager.GetTexture("monster"));
}

void Monster::DrawMonster(sf::RenderWindow& window)
{
	window.draw(body);
}

void Monster::Update()
{
	if (!changeType && !error)
	{
		animation.ChangeFrame(currentType, currentFrame, assetManager, body, changeType);
	}
	else if(changeType && !error)
	{
		if (counter == randomNumber)
		{
			if (currentFrame != 6 && newType != NORMAL)
			{
				newType = currentType;
				while (currentType == newType)
				{
					random = rand() % 4;
					switch (random)
					{
					case 0:
						newType = LEFT;
						break;
					case 1:
						newType = RIGHT;
						break;
					case 2:
						newType = UP;
						break;
					case 3:
						newType = DOWN;
						break;
					}
				}
			}
			animation.ChangeType(currentType, newType, currentFrame, assetManager, body, changeType, randomNumber);
			
			counter = 0;
		}
		else
		{
			counter++;
			changeType = false;
			animation.ChangeFrame(currentType, currentFrame, assetManager, body, changeType);
		}
	}
}

sf::RectangleShape Monster::GetBody()
{
	return body;
}

void Monster::Error(bool isWrong)
{
	if (isWrong)
	{
		body.setTexture(assetManager.GetTexture("monster_error"));
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

void Monster::Stop()
{
	if (changeType == true)
	{
		newType = NORMAL;
		counter = randomNumber;
		if (currentType == NORMAL)
		{
			stop = true;
			error = true;
			body.setTexture(assetManager.GetTexture("monster"));
		}
	}
}