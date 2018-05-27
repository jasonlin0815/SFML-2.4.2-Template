#include "boid.h"
#include "math.h"

#define MAX_SPEED 0.4f
#define MAX_FORCE 0.01f

#define BOID_RADIUS 5

static Vector2f limit(Vector2f a, float l)
{
    float mag = Math::Magnitude(a);
    if (mag > MAX_SPEED)
    {
        float ratio = MAX_SPEED / mag;
        a *= ratio;
    }

    return a;
}

Boid::Boid(Vector2f loc)
{
    pos = loc;
    vel = Vector2f(0, 0);
    acc = Vector2f(0, 0);

    maxspeed = MAX_SPEED;
    maxforce = MAX_FORCE;

    // Set boid size
    setRadius(BOID_RADIUS);
    setOrigin(Vector2f(BOID_RADIUS, BOID_RADIUS));
    setPosition(pos);
}

void Boid::seek(Vector2f target)
{
    Vector2f desired = target - pos;
    desired = Math::Normalize(desired);
    desired *= MAX_SPEED;

    Vector2f steer = desired - vel;
    steer = limit(steer, MAX_FORCE);
    applyForce(steer);
}

void Boid::update(float dt)
{
    // Apply acceleration
    vel += acc;

    // Limit velocity by max speed
    vel = limit(vel, MAX_SPEED);

    // Apply velocity
    pos += vel;
    setPosition(pos);

    acc = Vector2f(0, 0);
}

void Boid::applyForce(Vector2f force)
{
    acc += force;
}
