#pragma once
#include "AssetManager.h"

class ScrollBar
{
private:
	sf::RectangleShape scrollbarBackground;
	sf::RectangleShape scrollbarHandle;

	float maxHandleOffset;
	float scrollAmount;
	float currentHandleOffset;
	float newHandleOffset;

public:

	ScrollBar();
	~ScrollBar();

};