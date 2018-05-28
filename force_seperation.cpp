#include "force_seperation.h"
#include "math.h"

#include <iostream>

#define DESIRED_SEPERATION 20.0f

Vector2f Seperation::getSeperateForce(Boid* b, vector<Boid*> boids)
{
    int count = 0;
    Vector2f location = b->getPosition();
    Vector2f sum = Vector2f(0, 0);

    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        Vector2f otherLocation = (*it)->getPosition();

        float d = Math::Distance(location, otherLocation);

        if ((*it) != b && (d < DESIRED_SEPERATION))
        {
            Vector2f diff = Math::Sub(location, otherLocation);
            diff = Math::Normalize(diff);

            sum += diff;
            ++count;
        }
    }

    if (count > 0)
    {
        sum = sum * (1.0f / (float)count);
    }
    return sum;
}