#include "ScrollBar.h"


ScrollBar::ScrollBar(sf::Vector2f position, float height, int howManyOptions, sf::Color backgroundColor, sf::Color handleColor, std::string type, sf::RenderWindow& window) : type(type), window(window)
{
	scrollbarBackground.setFillColor(backgroundColor);
	scrollbarBackground.setOutlineColor(sf::Color::Black);
	scrollbarBackground.setOutlineThickness(2);
	scrollbarBackground.setPosition(position);

	scrollbarHandle.setFillColor(handleColor);
	maxHandleOffset = height - handleHight;

	handleHight = int(height / howManyOptions);

	if (type == "vertically")
	{
		scrollbarBackground.setSize({ SCROLLBAR_BACKGROUND, height });
		
		scrollbarHandle.setSize({ SCROLLBAR_HANDLE, handleHight });
		
		scrollbarHandle.setPosition(position.x + ((SCROLLBAR_BACKGROUND - SCROLLBAR_HANDLE) / 2), position.y);
	}
	else
	{
		scrollbarBackground.setSize({ height , SCROLLBAR_BACKGROUND / 2});

		scrollbarHandle.setSize({ handleHight, SCROLLBAR_HANDLE + 20});

		scrollbarHandle.setPosition(position.x, position.y + ((SCROLLBAR_BACKGROUND - SCROLLBAR_HANDLE) / 2) - (10 + SCROLLBAR_BACKGROUND / 4));

		scrollbarHandle.setOutlineColor(sf::Color::Black);
		scrollbarHandle.setOutlineThickness(2);
	}
}

void ScrollBar::Update(sf::Event event, int& counter, int maxCounter, int minCounter)
{
	if (type == "vertically")
	{
		if (event.type == sf::Event::MouseWheelScrolled)
		{
			if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
			{
				scrollAmount = event.mouseWheelScroll.delta;
				currentHandleOffset = scrollbarHandle.getPosition().y - scrollbarBackground.getPosition().y;
				newHandleOffset = currentHandleOffset - scrollAmount * handleHight;
				newHandleOffset = std::max(0.0f, std::min(newHandleOffset, maxHandleOffset));
				if ((counter < maxCounter && scrollAmount > 0) || (counter > minCounter && scrollAmount < 0))
				{
					counter += scrollAmount / std::abs(scrollAmount);
				}
				scrollbarHandle.setPosition(scrollbarHandle.getPosition().x, scrollbarBackground.getPosition().y + newHandleOffset);
			}
		}
	}
	else
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				if (scrollbarHandle.getGlobalBounds().contains(mousePos))
				{
					isDragging = true;
					dragOffset = mousePos - scrollbarHandle.getPosition();
				}
			}
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				isDragging = false;
			}
		}
		else if (event.type == sf::Event::MouseMoved)
		{
			if (isDragging)
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				float newHandleOffset = mousePos.x - scrollbarBackground.getPosition().x - dragOffset.x;
				newHandleOffset = std::max(0.0f, std::min(newHandleOffset, maxHandleOffset));
				counter = minCounter + std::round((newHandleOffset / maxHandleOffset) * (maxCounter - minCounter)) - 1;
				scrollbarHandle.setPosition(scrollbarBackground.getPosition().x + newHandleOffset, scrollbarHandle.getPosition().y);
			}
		}
	}
}

void ScrollBar::Draw()
{
	window.draw(scrollbarBackground);
	window.draw(scrollbarHandle);
}
