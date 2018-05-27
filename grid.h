#pragma once
#include <vector>
#include "boid.h"

using namespace std;

class Grid
{
private:
    vector<vector<Boid>*>* grid;

public:
    Grid();
};