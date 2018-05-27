#include "boid_system.h"
#include "setting.h"

BoidSystem::BoidSystem()
{
    boids = vector<Boid*>();
}

BoidSystem::BoidSystem(int n)
{
    for (int i = 0; i < n; ++i)
    {
        boids.push_back(new Boid(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)));
    }
}

void BoidSystem::update(float dt)
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        (*it)->update(dt);
    }
}

void BoidSystem::setTarget(Vector2f target)
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        (*it)->seek(target);
    }
}

void BoidSystem::display(RenderWindow& window)
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        window.draw(*(*it));
    }
}

BoidSystem::~BoidSystem()
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end();)
    {
        it = boids.erase(it);
    }
}
