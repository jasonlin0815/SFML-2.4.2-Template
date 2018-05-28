#pragma once
#include <vector>
#include "boid.h"

using namespace std;

class Alignment
{
private:
public:
    static Vector2f getAlignmentForce(Boid* b, vector<Boid*> boids);
};