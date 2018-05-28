#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Util
{
private:
public:
    static Vector2f limit(Vector2f a, float limit);
};