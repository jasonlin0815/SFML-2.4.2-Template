#include "boid_system.h"

BoidSystem::BoidSystem()
{
    boids = new vector<Boid>();
}

void BoidSystem::update(float dt)
{
    for (vector<Boid>::iterator it = boids->begin(); it != boids->end(); ++it)
    {
        it->update(dt);
    }
}
