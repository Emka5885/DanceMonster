#include "GameState.h"

GameState::GameState(GameDataReference data) : data(data)
{
}

void GameState::Init()
{
	barOfNotes = new BarOfNotes(data->window, data->assets);
	monster = new Monster(data->assets);
    music = new Music();
    score = 0;
    scoreText.setFont(data->assets.GetFont("scoreFont"));
    SetNewScore();
    scoreText.setCharacterSize(50);
    scoreText.setPosition(50, 25);
    music->StartMusic();
    clock.restart();
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
        if (clock.getElapsedTime()-sf::seconds(6) >= sf::seconds(1))//music->MusicTime())
        {
            std::cout << "Stop\n";
            monster->Stop();
            barOfNotes->stop = true;
        }
        else if (errorStart)
        {
            bool isWrong = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                isWrong = !barOfNotes->Check(LEFT);
                monster->Error(isWrong);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                isWrong = !barOfNotes->Check(RIGHT);
                monster->Error(isWrong);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                isWrong = !barOfNotes->Check(UP);
                monster->Error(isWrong);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                }
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                isWrong = !barOfNotes->Check(DOWN);
                monster->Error(isWrong);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                }
            }
            if (isWrong)
            {
                helperClock.restart();
                errorStop = true;
            }
        }
    }

    if (start && helperClock.getElapsedTime() >= sf::seconds(0.9))
    {
        errorStart = true;
        start = false;
        monster->Start();
    }
    else if (errorStop && helperClock.getElapsedTime() >= sf::seconds(3) && !monster->stop)
    {
        monster->Error(false);
        errorStop = false;
    }

    if (frameClock.getElapsedTime() >= sf::seconds(0.3) && !monster->stop)
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

    data->window.draw(scoreText);
	barOfNotes->DrawBar();
	monster->DrawMonster(data->window);
	barOfNotes->Update(dtClock.restart().asSeconds());

	data->window.display();
}

void GameState::SetNewScore()
{
    scoreText.setString("score: " + std::to_string(score));
}
