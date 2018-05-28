#include "force_cohesion.h"
#include <SFML/Graphics.hpp>
#include "boid.h"
#include "math.h"
#include <vector>

using namespace std;

#define COHESION_RADIUS 50

Vector2f Cohesion::getCohesionForce(Boid* b, vector<Boid*> boids)
{
    Vector2f location = b->getPosition();
    Vector2f sum = Vector2f(0, 0);
    int count = 0;
    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        Vector2f otherLocation = (*it)->getPosition();
        float d = Math::Distance(location, otherLocation);

        if ((*it) != b && d < COHESION_RADIUS)
        {
            sum += otherLocation;
            ++count;
        }
    }

    if (count > 0)
    {
        sum = sum * (1.0f / (float)count);
        return b->seek(sum);
    }

    return Vector2f(0, 0);
}
