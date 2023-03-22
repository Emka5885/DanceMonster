#include "GameState.h"
#include "EndGameState.h"

GameState::GameState(GameDataReference data) : data(data)
{
}

void GameState::Init()
{
	barOfNotes = new BarOfNotes(data->window, data->assets);
	monster = new Monster(data->assets);
    music = new Music();
    combo = 0;
    backgroundColor = sf::Color(0x1A1A1Aff);
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
        if (event.type == sf::Event::KeyPressed && errorStart && !monster->stop)
        {
            bool isWrong = false;
            std::string arrow = data->input.checkArrow(event.key.code);
            if (arrow == LEFT)
            {
                isWrong = !barOfNotes->Check(LEFT);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == RIGHT)
            {
                isWrong = !barOfNotes->Check(RIGHT);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == UP)
            {
                isWrong = !barOfNotes->Check(UP);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == DOWN)
            {
                isWrong = !barOfNotes->Check(DOWN);
                if (!isWrong)
                {
                    score++;
                    SetNewScore();
                    combo++;
                    monster->Error(false);
                }
            }
            if (isWrong)
            {
                fail = true;
            }
        }
    }
}

void GameState::Update(float dt)
{
    if (fail)
    {
        if (score > 0)
        {
            score--;
            SetNewScore();
        }
        combo = 0;
        monster->Error(true);
        helperClock.restart();
        errorStop = true;
        fail = false;
    }

    if (clock.getElapsedTime() >= music->MusicTime() - sf::seconds(9))
    {
        monster->Stop();
    }
    else if (clock.getElapsedTime() >= music->MusicTime() - sf::seconds(13))
    {
        barOfNotes->stop = true;
        helperClock.restart();
    }

    if (start && helperClock.getElapsedTime() >= sf::seconds(0.9))
    {
        errorStart = true;
        start = false;
        monster->Start();
    }
    else if (errorStop && helperClock.getElapsedTime() >= sf::seconds(3) && !barOfNotes->stop)
    {
        monster->Error(false);
        errorStop = false;
    }
    else if (barOfNotes->stop && helperClock.getElapsedTime() >= sf::seconds(4.2))
    {
        data->machine.AddState(stateReference(new EndGameState(data, &scoreText)), true);
    }

    if (frameClock.getElapsedTime() >= sf::seconds(0.3) && !monster->stop)
    {
        monster->Update();
        frameClock.restart();
    }

    if (combo >= 10)
    {
        barOfNotes->ChangeSpeed(barOfNotes->speed+=18);
        combo = 0;
    }

    barOfNotes->Update(dtClock.restart().asSeconds(), combo);

    barOfNotes->IncreaseWhiteShape();
}

void GameState::Draw(float dt)
{
	data->window.clear(backgroundColor);

    data->window.draw(scoreText);
	barOfNotes->DrawBar();
	monster->DrawMonster(data->window);

	data->window.display();
}

void GameState::SetNewScore()
{
    scoreText.setString("score: " + std::to_string(score));
}
