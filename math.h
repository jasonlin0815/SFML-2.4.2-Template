#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Math
{
private:
public:
    static Vector2f Sub(Vector2f a, Vector2f b);
    static Vector2f Add(Vector2f a, Vector2f b);
    static Vector2f Multiply(Vector2f a, float k);
    static Vector2f Normalize(Vector2f a);
    static float Length(Vector2f a);
    static float Magnitude(Vector2f a);
    static Vector2f Dot(Vector2f a, Vector2f b);
    static float Cross(Vector2f a, Vector2f b);
    static float AngleBetween(Vector2f a, Vector2f b);
};