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

    bool alignmentToggle = true;
    bool seperationToggle = true;
    bool cohesionToggle = true;

    int removeCount = 0;

public:
    BoidSystem();
    BoidSystem(int n);

    void update(float dt);
    void setTarget(Vector2f target);
    
    void display(RenderWindow& window);

    void toggleAlignment();
    void toggleSeperation();
    void toggleCohesion();

    void add(Vector2f pos);
    void remove();

    ~BoidSystem();
};