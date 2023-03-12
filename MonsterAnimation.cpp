#include "MonsterAnimation.h"

MonsterAnimation::MonsterAnimation()
{
}

void MonsterAnimation::ChangeFrame(std::string currentType, int& frame, AssetManager& assetManager, sf::RectangleShape& body)
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
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_r1"));
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
			break;
		case 4:
			frame = 1;
			body.setTexture(&assetManager.GetTexture("monster_l1"));
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
			break;
		}
	}
}

void MonsterAnimation::ChangeType(std::string& currentType, std::string type, int& frame, AssetManager& assetManager, sf::RectangleShape& body)
{

}
