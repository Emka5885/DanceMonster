#include "GameState.h"
#include "EndGameState.h"

GameState::GameState(GameDataReference data) : data(data)
{
}

void GameState::Init()
{
	barOfNotes = new BarOfNotes(data->window, data->assets);
	monster = new Monster(data->assets);
    music = new Music(data->assets);
    combos = new Combo(data->assets, monster);
    errorSound = &data->assets.GetSound("error");
    counter = 0;
    combo = 0;
    combos->comboTime = false;
    backgroundColor = sf::Color(0x1A1A1Aff);
    music->StartMusic();
    clock.restart();
    combosClock.restart();
    data->widgets->SetNewTime(music->MusicTime().asSeconds()-6, true);
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
                    data->widgets->SetNewScore(data->widgets->GetScore() + 1);
                    counter++;
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == RIGHT)
            {
                isWrong = !barOfNotes->Check(RIGHT);
                if (!isWrong)
                {
                    data->widgets->SetNewScore(data->widgets->GetScore() + 1);
                    counter++;
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == UP)
            {
                isWrong = !barOfNotes->Check(UP);
                if (!isWrong)
                {
                    data->widgets->SetNewScore(data->widgets->GetScore() + 1);
                    counter++;
                    combo++;
                    monster->Error(false);
                }
            }
            else if (arrow == DOWN)
            {
                isWrong = !barOfNotes->Check(DOWN);
                if (!isWrong)
                {
                    data->widgets->SetNewScore(data->widgets->GetScore() + 1);
                    counter++;
                    combo++;
                    monster->Error(false);
                }
            }
            if (isWrong)
            {
                fail = true;
                errorSound->play();
            }
        }
    }
}

void GameState::Update(float dt)
{
    if (fail)
    {
        if (data->widgets->GetScore() > 0)
        {
            data->widgets->SetNewScore(data->widgets->GetScore() - 1);
        }
        counter = 0;
        combo = 0;
        combos->comboTime = false;
        monster->Error(true);
        helperClock.restart();
        errorStop = true;
        fail = false;
    }

    if (combosClock.getElapsedTime() >= sf::seconds(0.6))
    {
        //combos->ChangeColors();
        combosClock.restart();
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
        data->machine.RemoveState();
        data->machine.AddState(stateReference(new EndGameState(data)), true);
    }

    if (frameClock.getElapsedTime() >= sf::seconds(0.3) && !monster->stop)
    {
        monster->Update();
        frameClock.restart();
    }

    if (counter >= 10)
    {
        barOfNotes->ChangeSpeed(barOfNotes->speed+=18);
        counter = 0;
    }
    if (combo >= 10)
    {
        combos->comboTime = true;
        data->machine.AddState(stateReference(new EndGameState(data)), true);
    }
    combos->UpdateMonsters(combos->comboTime);

    barOfNotes->Update(dtClock.restart().asSeconds(), counter);

    barOfNotes->IncreaseWhiteShape();

    data->widgets->TimeUpdate();
}

void GameState::Draw(float dt)
{
	data->window.clear(backgroundColor);

    data->widgets->DrawScore(data->window);
    data->widgets->DrawTime(data->window);
	barOfNotes->DrawBar();
	monster->DrawMonster(data->window);
    //combos->DrawColors(data->window);
    combos->DrawMonsters(data->window);

	data->window.display();
}