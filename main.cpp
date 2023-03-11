﻿#include "BarOfNotes.h"
#include "Monster.h"

int main()
{
    AssetManager assetManager;
    sf::Clock dtClock;
    sf::Clock frameClock;
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    //sf::RectangleShape shape;
    //shape.setSize({ 200,200 });

    BarOfNotes b(window, assetManager);
    Note n(assetManager);
    Monster m(assetManager);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                b.Check(LEFT);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                b.Check(RIGHT);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                b.Check(UP);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                b.Check(DOWN);
            }
        }

        if (frameClock.getElapsedTime() >= sf::seconds(0.5))
        {
            m.Update(LEFT);
            frameClock.restart();
        }


        window.clear(sf::Color(0x1A1A1Aff));
        //window.draw(shape);
        b.DrawBar();
        m.DrawMonster(window);
        b.Update(dtClock.restart().asSeconds());
        //n.DrawArrow(window);
        window.display();
    }

    return 0;
}