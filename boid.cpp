#include "boid.h"
#include "math.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "setting.h"
#include "util.h"

using namespace std;

#define BOID_RADIUS 5

#define PI  3.14159f

Boid::Boid(Vector2f loc)
{
    pos = loc;
    vel = Vector2f(0, 0);

    // Give random initial acceleration
    int launchAngle = rand() % 360;
    acc = Vector2f(cos(launchAngle * PI / 180.0f), sin(launchAngle * PI / 180.0f));

    maxspeed = MAX_SPEED;
    maxforce = MAX_FORCE;

    // Set boid size
    setRadius(BOID_RADIUS);
    setOrigin(Vector2f(BOID_RADIUS, BOID_RADIUS));
    setPosition(pos);
}

Vector2f Boid::seek(Vector2f target)
{
    Vector2f desired = target - pos;

    float d = Math::Magnitude(desired);
    desired = Math::Normalize(desired);

    if (d < 100)
    {
        float m = d / 100.0f * MAX_SPEED;
    }
    else
    {
        desired *= MAX_SPEED;
    }

    Vector2f steer = desired - vel;
    steer = Util::limit(steer, MAX_FORCE);

    return steer;
}

void Boid::update(float dt)
{
    // Apply acceleration
    vel += acc;

    // Limit velocity by max speed
    vel = Util::limit(vel, MAX_SPEED);

    // Apply velocity
    pos += vel;
    setPosition(pos);

    acc = Vector2f(0, 0);
}

void Boid::applyForce(Vector2f force)
{
    acc += force;
}

Vector2f Boid::getVelocity()
{
    return vel;
}
