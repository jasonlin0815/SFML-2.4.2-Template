#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Boid : public CircleShape
{
private:
    Vector2f pos;
    Vector2f vel;
    Vector2f acc;

    float maxforce;
    float maxspeed;

public:
    Boid() {};
    Boid(Vector2f loc);

    void update(float dt);
    void seek(Vector2f target);
    void applyForce(Vector2f force);
};

