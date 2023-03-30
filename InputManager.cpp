#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::isButtonClicked(sf::RectangleShape object, sf::Mouse::Button button, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

        if (tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
    return sf::Mouse::getPosition(window);
}

std::string InputManager::checkArrow(sf::Keyboard::Key button)
{
    if (button == sf::Keyboard::Left)
    {
        return LEFT;
    }
    else if (button == sf::Keyboard::Right)
    {
        return RIGHT;
    }
    else if (button == sf::Keyboard::Down)
    {
        return DOWN;
    }
    else if (button == sf::Keyboard::Up)
    {
        return UP;
    }
    return ERROR;
}
