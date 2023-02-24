#include "BarOfNotes.h"

#define WIDTH 1200
#define HEIGHT 800

int main()
{
    AssetManager assetManager;
    sf::Clock dtClock;
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
    //sf::RectangleShape shape;
    //shape.setSize({ 200,200 });

    BarOfNotes b(WIDTH, HEIGHT, window, assetManager);
    Note n(assetManager);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Red);
        //window.draw(shape);
        b.DrawBar();
        b.Update(dtClock.restart().asSeconds());
        //n.DrawArrow(window);
        window.display();
    }

    return 0;
}