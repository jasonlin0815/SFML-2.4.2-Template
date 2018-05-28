#include "boid_system.h"
#include "setting.h"
#include "force_seperation.h"
#include "force_alignment.h"
#include "force_cohesion.h"

#include <iostream>

#define SEPERATION_WEIGHT 1.5f
#define ALIGNMENT_WEIGHT 1.0f
#define COHESION_WEIGHT 1.0f

BoidSystem::BoidSystem()
{
    cout << "Boid System" << endl;
    boids = vector<Boid*>();
    alignmentToggle = true;
    seperationToggle = true;
    cohesionToggle = true;
}

BoidSystem::BoidSystem(int n)
{
    BoidSystem();
    for (int i = 0; i < n; ++i)
    {
        boids.push_back(new Boid(Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2)));
    }
}

void BoidSystem::update(float dt)
{
    // Remove the counts registered
    for (int i = 0; i < removeCount; ++i)
    {
        if (boids.size() == 0)
        {
            break;
        }
        boids.pop_back();
    }
    removeCount = 0;

    // Update the boids
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        (*it)->update(dt);
    }
}

void BoidSystem::setTarget(Vector2f target)
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        Vector2f steerForce = (*it)->seek(target);
        Vector2f seperation = Seperation::getSeperateForce((*it), boids) * SEPERATION_WEIGHT;
        Vector2f alignmenet = Alignment::getAlignmentForce((*it), boids) * ALIGNMENT_WEIGHT;
        Vector2f cohesion = Cohesion::getCohesionForce((*it), boids) * COHESION_WEIGHT;

        (*it)->applyForce(steerForce);
        if (seperationToggle)
        {
            (*it)->applyForce(seperation);
        }

        if (alignmentToggle)
        {
            (*it)->applyForce(alignmenet);
        }

        if (cohesionToggle)
        {
            (*it)->applyForce(cohesion);
        }
    }
}

void BoidSystem::display(RenderWindow& window)
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        window.draw(*(*it));
    }
}

void BoidSystem::toggleAlignment()
{
    alignmentToggle = !alignmentToggle;
    cout << "Alignment: " << ((alignmentToggle) ? "ON" : "OFF") << endl;
}

void BoidSystem::toggleCohesion()
{
    cohesionToggle = !cohesionToggle;
    cout << "Cohesion: " << ((cohesionToggle) ? "ON" : "OFF") << endl;
}

void BoidSystem::toggleSeperation()
{
    seperationToggle = !seperationToggle;
    cout << "Seperation: " << ((seperationToggle) ? "ON" : "OFF") << endl;
}

void BoidSystem::add(Vector2f pos)
{
    Boid* boid = new Boid(pos);
    boids.push_back(boid);
}

void BoidSystem::remove()
{
    ++removeCount;
}

BoidSystem::~BoidSystem()
{
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end();)
    {
        it = boids.erase(it);
    }
}
