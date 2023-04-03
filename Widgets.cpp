#include "Widgets.h"

Widgets::Widgets(AssetManager& assetManager) : assetManager(assetManager)
{
    scoreText.setFont(assetManager.GetFont("standardFont"));
    SetNewScore(0);
    scoreText.setCharacterSize(50);
    SetScorePosition({ 50, 25 });

    timeText.setFont(assetManager.GetFont("standardFont"));
    timeText.setCharacterSize(50);
    timeText.setPosition(900, 25);
    time = 0;
}

void Widgets::SetNewScore(int newScore)
{
    score = newScore;
    scoreText.setString("score: " + std::to_string(score));
}

int Widgets::GetScore()
{
    return score;
}

void Widgets::SetScorePosition(sf::Vector2f newPosition)
{
    scoreText.setPosition(newPosition);
}

sf::FloatRect Widgets::GetScoreGlobalBounds()
{
    return scoreText.getGlobalBounds();
}

void Widgets::SetNewTime(int newTime, bool newMusic)
{
    timeClock.restart();

    time = newTime;
    if (newMusic)
    {
        musicTime = time;
    }

    timeText.setString("time: " + std::to_string(time) + "s");
}

int Widgets::GetTime()
{
    return musicTime;
}

void Widgets::TimeUpdate()
{
    if (timeClock.getElapsedTime() >= sf::seconds(1) && time > 0)
    {
        SetNewTime(--time, false);
    }
}

void Widgets::DrawScore(sf::RenderWindow& window)
{
    window.draw(scoreText);
}

void Widgets::DrawTime(sf::RenderWindow& window)
{
    window.draw(timeText);
}