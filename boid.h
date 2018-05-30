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

    Texture texture;

public:
    Boid() {};
    Boid(Vector2f loc);

    void update(float dt);
    Vector2f seek(Vector2f target);
    void applyForce(Vector2f force);

    Vector2f getVelocity();
};

