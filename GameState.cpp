#include "GameState.h"

GameState::GameState(GameDataReference data) : data(data)
{
}

void GameState::Init()
{
	barOfNotes = new BarOfNotes(data->window, data->assets);
	monster = new Monster(data->assets);
}

void GameState::HandleInput()
{
    sf::Event event;

    while (data->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            data->window.close();
        }
        if (errorStart)
        {
            bool isWrong = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                isWrong = barOfNotes->Check(LEFT);
                monster->Error(!isWrong);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                isWrong = barOfNotes->Check(RIGHT);
                monster->Error(!isWrong);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                isWrong = barOfNotes->Check(UP);
                monster->Error(!isWrong);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                isWrong = barOfNotes->Check(DOWN);
                monster->Error(!isWrong);
            }
            if (isWrong)
            {
                helperClock.restart();
                errorStop = true;
            }
        }
    }

    if (start && helperClock.getElapsedTime() >= sf::seconds(3))
    {
        errorStart = true;
        start = false;
        monster->Start();
    }
    else if (errorStop && helperClock.getElapsedTime() >= sf::seconds(3))
    {
        monster->Error(false);
        errorStop = false;
    }

    if (frameClock.getElapsedTime() >= sf::seconds(0.3))
    {
        monster->Update();
        frameClock.restart();
    }
}

void GameState::Update(float dt)
{
}

void GameState::Draw(float dt)
{
	data->window.clear(sf::Color(0x1A1A1Aff));

	barOfNotes->DrawBar();
	monster->DrawMonster(data->window);
	barOfNotes->Update(dtClock.restart().asSeconds());

	data->window.display();
}
