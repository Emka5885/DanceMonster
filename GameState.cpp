#include "GameState.h"
#include "EndGameState.h"

GameState::GameState(GameDataReference data, sf::Sound* menuSound, sf::Music* menuBackgroundMusic) : data(data), menuSound(menuSound), menuBackgroundMusic(menuBackgroundMusic)
{
    data->widgets = new Widgets(data->assets);
    barOfNotes = new BarOfNotes(data->window, data->assets);
    monster = new Monster(data->assets);
    combos = new Combo(data->assets, monster);
    counter = 0;
    combo = 0;
    combos->comboTime = false;
    backgroundColor = sf::Color(0x1A1A1Aff);
    music = nullptr;
    comboCounter = true;
}

void GameState::Init()
{
    clock.restart();
    combosClock.restart();

    std::fstream file;
    file.open("musicOptions.txt", std::ios::in);
    if (file.is_open())
    {
        std::string helperLine;
        while (file >> helperLine)
        {
            if (std::isdigit(helperLine[0]))
            {
                musicOptionsFromFile.push_back(std::stoi(helperLine));
            }
            else if (helperLine == "true")
            {
                optionsFromFile.push_back(true);
            }
            else if (helperLine == "false")
            {
                optionsFromFile.push_back(false);
            }
        }
        file.close();
    }

    if (!errorSoundBuffer.loadFromFile("resources/sounds/error-89206.wav"))
    {
        std::cout << "Error sound - error sound in game.\n" << std::endl;
    }
    if (!comboSoundBuffer.loadFromFile("resources/sounds/combo.wav"))
    {
        std::cout << "Error sound - combo time.\n" << std::endl;
    }

    errorSound.setBuffer(errorSoundBuffer);
    errorSound.setVolume(musicOptionsFromFile[2]);
    comboSound.setBuffer(comboSoundBuffer);
    comboSound.setVolume(musicOptionsFromFile[4]);

    music = new Music(data->assets, musicOptionsFromFile[3]);
    music->StartMusic();
    data->widgets->SetNewTime(music->MusicTime().asSeconds() - 6, true);

    comboText.setFont(data->assets.GetFont("standardFont"));
    comboText.setString("score: x1");
    comboText.setCharacterSize(20);

    pointsText = comboText;
    pointsText.setPosition({ 50, 85 });

    comboCounter = optionsFromFile[1];
}

void GameState::AddPoints()
{
    if (combo < 10)
    {
        data->widgets->SetNewScore(data->widgets->GetScore() + 1);
    }
    else
    {
        data->widgets->SetNewScore(data->widgets->GetScore() + 1 + 1 * combo / 10);
    }
    counter++;
    combo++;
    monster->Error(false);
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            music->StopMusic();
            data->machine.RemoveState();
            data->machine.AddState(stateReference(new EndGameState(data, menuSound, menuBackgroundMusic, maxCombo, optionsFromFile[1])), true);
        }
        if (event.type == sf::Event::KeyPressed && errorStart && !monster->stop && canCheckArrow)
        {
            canCheckArrow = false;
            bool isWrong = false;
            std::string arrow = data->input.checkArrow(event.key.code);
            if (arrow == LEFT)
            {
                isWrong = !barOfNotes->Check(LEFT);
                if (!isWrong)
                {
                    AddPoints();
                }
            }
            else if (arrow == RIGHT)
            {
                isWrong = !barOfNotes->Check(RIGHT);
                if (!isWrong)
                {
                    AddPoints();
                }
            }
            else if (arrow == UP)
            {
                isWrong = !barOfNotes->Check(UP);
                if (!isWrong)
                {
                    AddPoints();
                }
            }
            else if (arrow == DOWN)
            {
                isWrong = !barOfNotes->Check(DOWN);
                if (!isWrong)
                {
                    AddPoints();
                }
            }
            if (isWrong)
            {
                fail = true;
                errorSound.play();
            }
        }
        else if (event.type == sf::Event::KeyReleased && !canCheckArrow)
        {
            canCheckArrow = true;
        }
    }
}

void GameState::Update()
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
        combosClock.restart();
    }

    if (clock.getElapsedTime() >= music->MusicTime() - sf::seconds(9))
    {
        monster->Stop();
    }
    else if (clock.getElapsedTime() >= music->MusicTime() - sf::seconds(13))
    {
        combos->comboTime = false;
        stopCombo = true;
        barOfNotes->stop = true;
        helperClock.restart();
    }

    if (start && helperClock.getElapsedTime() >= sf::seconds(2.5))
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
        data->machine.AddState(stateReference(new EndGameState(data, menuSound, menuBackgroundMusic, maxCombo, optionsFromFile[1])), true);
    }

    if (frameClock.getElapsedTime() >= sf::seconds(0.3) && !monster->stop)
    {
        monster->Update();
        frameClock.restart();
    }

    if (counter >= 10)
    {
        barOfNotes->ChangeSpeed(barOfNotes->speed+=15);
        counter = 0;
    }

    if (combo == 9)
    {
        playComboSound = true;
    }
    else if (combo == 10 && playComboSound)
    {
        playComboSound = false;
        comboSound.play();
    }
    if (combo >= 10 && optionsFromFile[0] && !stopCombo)
    {
        combos->comboTime = true;
    }
    combos->UpdateMonsters(combos->comboTime);

    barOfNotes->Update(dtClock.restart().asSeconds(), counter);

    barOfNotes->IncreaseWhiteShape();

    data->widgets->TimeUpdate();

    if (combo % 10 == 0)
    {
        if (maxCombo < combo)
        {
            maxCombo = combo;
        }
        pointsText.setString("score: x" + std::to_string(1 + combo / 10));
    }
    if (combo % 10 == 0 && helperCombo != combo && comboCounter)
    {
        comboText.setString("combo: " + std::to_string(combo));
        comboText.setPosition({ WIDTH - 25 - comboText.getGlobalBounds().width, HEIGHT - 200 });
        helperCombo = combo;
        comboClock.restart();
    }
}

void GameState::Draw()
{
	data->window.clear(backgroundColor);

    data->widgets->DrawScore(data->window);
    data->widgets->DrawTime(data->window);
	barOfNotes->DrawBar();
	monster->DrawMonster(data->window);
    combos->DrawMonsters(data->window);
    if (helperCombo != 0 && comboClock.getElapsedTime() <= sf::seconds(2.2) && comboCounter)
    {
        data->window.draw(comboText);
    }
    data->window.draw(pointsText);
    data->window.draw(data->name);

	data->window.display();
}