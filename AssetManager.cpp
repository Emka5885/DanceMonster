#include "AssetManager.h"

AssetManager::AssetManager()
{
	LoadTexture("left", "resources/arrows/LeftArrow.png");
	LoadTexture("right", "resources/arrows/RightArrow.png");
	LoadTexture("down", "resources/arrows/DownArrow.png");
	LoadTexture("up", "resources/arrows/UpArrow.png");
	LoadTexture("monster", "resources/monster/monster.png");
	LoadTexture("monster_d1", "resources/monster/Down/d_monster_01.png");
	LoadTexture("monster_d2", "resources/monster/Down/d_monster_02.png");
	LoadTexture("monster_d3", "resources/monster/Down/d_monster_03.png");
	LoadTexture("monster_d4", "resources/monster/Down/d_monster_04.png");
	LoadTexture("monster_d5", "resources/monster/Down/d_monster_05.png");
	LoadTexture("monster_d6", "resources/monster/Down/d_monster_06.png");
	LoadTexture("monster_l1", "resources/monster/Left/l_monster_01.png");
	LoadTexture("monster_l2", "resources/monster/Left/l_monster_02.png");
	LoadTexture("monster_l3", "resources/monster/Left/l_monster_03.png");
	LoadTexture("monster_r1", "resources/monster/Right/r_monster_01.png");
	LoadTexture("monster_r2", "resources/monster/Right/r_monster_02.png");
	LoadTexture("monster_r3", "resources/monster/Right/r_monster_03.png");
	LoadTexture("monster_r4", "resources/monster/Right/r_monster_04.png");
	LoadTexture("monster_r5", "resources/monster/Right/r_monster_05.png");
	LoadTexture("monster_u1", "resources/monster/Up/u_monster_01.png");
	LoadTexture("monster_u2", "resources/monster/Up/u_monster_02.png");
	LoadTexture("monster_u3", "resources/monster/Up/u_monster_03.png");
	LoadTexture("monster_u4", "resources/monster/Up/u_monster_04.png");
	LoadTexture("monster_u5", "resources/monster/Up/u_monster_05.png");
	LoadTexture("monster_u6", "resources/monster/Up/u_monster_06.png");
}

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;

	if (texture.loadFromFile(fileName))
	{
		this->textures[name] = texture;
	}
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
}

sf::Font& AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}