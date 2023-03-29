#include "Widgets.h"

Widgets::Widgets(AssetManager& assetManager) : assetManager(assetManager)
{
    scoreText.setFont(assetManager.GetFont("scoreFont"));
    SetNewScore(0);
    scoreText.setCharacterSize(50);
    SetScorePosition({ 50, 25 });
}

void Widgets::SetNewScore(int newScore)
{
    score = newScore;
    scoreText.setString("score: " + std::to_string(score));
}

void Widgets::DrawScore(sf::RenderWindow& window)
{
    window.draw(scoreText);
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
