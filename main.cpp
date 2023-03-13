#include "BarOfNotes.h"
#include "Monster.h"

int main()
{
    AssetManager assetManager;
    sf::Clock dtClock;
    sf::Clock frameClock;
    sf::Clock startClock;
    bool start = true;
    bool errorStart = false;
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
            if (errorStart)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    m.Error(!b.Check(LEFT));
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    m.Error(!b.Check(RIGHT));
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    m.Error(!b.Check(UP));
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    m.Error(!b.Check(DOWN));
                }
            }
        }

        if (start && startClock.getElapsedTime() >= sf::seconds(3))
        {
            errorStart = true;
            start = false;
            m.Start();
        }

        if (frameClock.getElapsedTime() >= sf::seconds(0.3))
        {
            m.Update();
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