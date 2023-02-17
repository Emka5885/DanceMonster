#include "Note.h"

int main()
{
    AssetManager assetManager;
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");
    //sf::RectangleShape shape;
    //shape.setSize({ 200,200 });

    Note n(assetManager);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        //window.draw(shape);
        n.DrawArrow(window);
        window.display();
    }

    return 0;
}