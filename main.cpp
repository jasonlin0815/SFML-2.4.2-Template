#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "setting.h"
#include "boid.h"

using namespace sf;

int main()
{
    Clock clock;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flocking!");
    Boid *b = new Boid(Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        window.clear();

        b->seek(Vector2f(Mouse::getPosition(window)));
        b->update(dt);
        window.draw(*b);

        window.display();
    }

    return 0;
}
