#pragma once
#include "boid.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class BoidSystem
{
private:
    vector<Boid*> boids;

public:
    BoidSystem();
    BoidSystem(int n);

    void update(float dt);
    void setTarget(Vector2f target);
    void display(RenderWindow& window);

    ~BoidSystem();
};