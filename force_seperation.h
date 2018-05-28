#pragma once
#include "boid.h"
#include <vector>

using namespace std;

class Seperation
{
private:
public:
    static Vector2f getSeperateForce(Boid *b, vector<Boid*> boids);
};