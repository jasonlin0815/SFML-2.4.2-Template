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

    srand((int)time(NULL));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case Event::Closed:
                {
                    window.close();
                    break;
                }

                case Event::KeyPressed:
                {
                    // Toggle Alignment
                    if (event.key.code == Keyboard::Num1)
                    {
                        bs->toggleAlignment();
                    }

                    // Toggle Seperation
                    if (event.key.code == Keyboard::Num2)
                    {
                        bs->toggleSeperation();
                    }

                    // Toggle Cohesion
                    if (event.key.code == Keyboard::Num3)
                    {
                        bs->toggleCohesion();
                    }
                }

                case Event::MouseButtonPressed:
                {
                    // Add boids
                    if (event.mouseButton.button == Mouse::Button::Left)
                    {
                        bs->add(Vector2f(Mouse::getPosition(window)));
                    }

                    // Remove boids from the end
                    if (event.mouseButton.button == Mouse::Button::Right)
                    {
                        bs->remove();
                    }
                }
            }
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
