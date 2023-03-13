#include "MonsterAnimation.h"

MonsterAnimation::MonsterAnimation()
{
}

void MonsterAnimation::ChangeFrame(std::string& currentType, int& frame, AssetManager& assetManager, sf::RectangleShape& body, bool& change)
{
	if (currentType == RIGHT)
	{
		switch (frame)
		{
		case 0:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_r1"));
			break;
		case 1:
			frame = 2;
			body.setTexture(&assetManager.GetTexture("monster_r2"));
			break;
		case 2:
			frame = 3;
			body.setTexture(&assetManager.GetTexture("monster_r3"));
			break;
		case 3:
			frame = 4;
			body.setTexture(&assetManager.GetTexture("monster_r4"));
			change = true;
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_r1"));
			change = false;
			break;
		}
	}
	else if (currentType == LEFT)
	{
		switch (frame)
		{
		case 0:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_l1"));
			break;
		case 1:
			frame = 2;
			body.setTexture(&assetManager.GetTexture("monster_l2"));
			break;
		case 2:
			frame = 3;
			body.setTexture(&assetManager.GetTexture("monster_l3"));
			break;
		case 3:
			frame = 4;
			body.setTexture(&assetManager.GetTexture("monster_l2"));
			change = true;
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_l1"));
			change = false;
			break;
		}
	}
	else if (currentType == DOWN)
	{
		switch (frame)
		{
		case 0:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_d1"));
			break;
		case 1:
			frame = 2;
			body.setTexture(&assetManager.GetTexture("monster_d2"));
			change = false;
			break;
		case 2:
			frame = 3;
			body.setTexture(&assetManager.GetTexture("monster_d3"));
			break;
		case 3:
			frame = 4;
			body.setTexture(&assetManager.GetTexture("monster_d4"));
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_d5"));
			change = true;
			break;
		}
	}
	else if (currentType == UP)
	{
		switch (frame)
		{
		case 0:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_u1"));
			break;
		case 1:
			frame = 2;
			body.setTexture(&assetManager.GetTexture("monster_u2"));
			change = false;
			break;
		case 2:
			frame = 3;
			body.setTexture(&assetManager.GetTexture("monster_u3"));
			break;
		case 3:
			frame = 4;
			body.setTexture(&assetManager.GetTexture("monster_u4"));
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_u5"));
			change = true;
			break;
		}
	}
}

void MonsterAnimation::ChangeType(std::string& currentType, std::string type, int& frame, AssetManager& assetManager, sf::RectangleShape& body, bool& change, int& randomNumber)
{
	if (currentType == RIGHT || currentType == LEFT)
	{
		body.setTexture(&assetManager.GetTexture("monster"));
		currentType = type;
		change = false;
		frame = 0;
		randomNumber = rand() % 5 + 1;
	}
	else if (currentType == DOWN)
	{
		switch (frame)
		{
		case 1:
			frame = 6;
			body.setTexture(&assetManager.GetTexture("monster_d6"));
			break;
		case 6:
			frame = 0;
			currentType = type;
			change = false;
			body.setTexture(&assetManager.GetTexture("monster"));
			randomNumber = rand() % 5 + 1;
			break;
		}
	}
	else if (currentType == UP)
	{
		switch (frame)
		{
		case 1:
			frame = 6;
			body.setTexture(&assetManager.GetTexture("monster_u6"));
			break;
		case 6:
			frame = 0;
			currentType = type;
			change = false;
			body.setTexture(&assetManager.GetTexture("monster"));
			randomNumber = rand() % 5 + 1;
			break;
		}
	}
	else
	{
		frame = 0;
		randomNumber = rand() % 5 + 1;
		change = false;

		int num = rand() % 4;
		switch (num)
		{
		case 0:
			currentType = LEFT;
			break;
		case 1:
			currentType = RIGHT;
			break;
		case 2:
			currentType = UP;
			break;
		case 3:
			currentType = DOWN;
			break;
		}
	}
}
