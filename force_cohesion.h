#pragma once
#include "boid.h"
#include <vector>

using namespace std;

class Cohesion
{
private:
public:
    static Vector2f getCohesionForce(Boid* b, vector<Boid*> boids);
};
