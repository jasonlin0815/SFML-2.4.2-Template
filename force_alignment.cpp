#include "force_alignment.h"
#include "math.h"
#include "setting.h"
#include "util.h"

#define ALIGN_RADIUS 50

Vector2f Alignment::getAlignmentForce(Boid* boid, vector<Boid*> boids)
{
    Vector2f sum = Vector2f(0, 0);
    int count = 0;
    Vector2f location = boid->getPosition();

    for (vector<Boid*>::iterator it = boids.begin(); it != boids.end(); ++it)
    {
        Vector2f otherLocation = (*it)->getPosition();
        float d = Math::Distance(location, otherLocation);

        if ((*it) != boid && d < ALIGN_RADIUS)
        {
            sum += (*it)->getVelocity();
            ++count;
        }
    }

    if (count > 0)
    {
        sum = sum * (1.0f / (float)count);
        sum = Math::Normalize(sum);
        sum *= MAX_SPEED;

        Vector2f steer = Math::Sub(sum, boid->getVelocity());
        steer = Util::limit(steer, MAX_FORCE);

        return steer;
    }

    return Vector2f(0, 0);
}