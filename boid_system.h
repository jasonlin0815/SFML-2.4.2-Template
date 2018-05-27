#pragma once
#include "boid.h"
#include <vector>

using namespace std;

class BoidSystem
{
private:
    vector<Boid> * boids;

public:
    BoidSystem();

    void update(float dt);
};