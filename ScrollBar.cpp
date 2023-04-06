#include "ScrollBar.h"


ScrollBar::ScrollBar(sf::Vector2f position, float height, int howManyOptions, sf::Color backgroundColor, sf::Color handleColor)
{
	scrollbarBackground.setSize({ SCROLLBAR_BACKGROUND_WIDTH, height });
	scrollbarBackground.setFillColor(backgroundColor);
	scrollbarBackground.setOutlineColor(sf::Color::Black);
	scrollbarBackground.setOutlineThickness(2);
	scrollbarBackground.setPosition(position);

	handleHight = int(height / howManyOptions);
	scrollbarHandle.setSize({ SCROLLBAR_HANDLE_WIDTH, handleHight });
	scrollbarHandle.setFillColor(handleColor);
	scrollbarHandle.setPosition(position.x + ((SCROLLBAR_BACKGROUND_WIDTH-SCROLLBAR_HANDLE_WIDTH)/2), position.y);

	maxHandleOffset = height - handleHight;
}

void ScrollBar::Update(sf::Event event, int& counter, int maxCounter, int minCounter)
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
				counter += scrollAmount  / std::abs(scrollAmount);
			}
			scrollbarHandle.setPosition(scrollbarHandle.getPosition().x, scrollbarBackground.getPosition().y + newHandleOffset);
		}
	}
}

void ScrollBar::Draw(sf::RenderWindow& window)
{
	window.draw(scrollbarBackground);
	window.draw(scrollbarHandle);
}
