#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "setting.h"
#include "boid_system.h"

using namespace sf;

int main()
{
    Clock clock;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flocking!");
    BoidSystem *bs = new BoidSystem(10);

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

        bs->setTarget(Vector2f(Mouse::getPosition(window)));
        bs->update(dt);
        bs->display(window);

        window.display();
    }

    return 0;
}
