#include "math.h"
#include <math.h>
#include <iostream>

using namespace std;

Vector2f Math::Add(Vector2f a, Vector2f b)
{
    return Vector2f(0, 0);
}

Vector2f Math::Sub(Vector2f a, Vector2f b)
{
    return Vector2f(0, 0);
}

Vector2f Math::Multiply(Vector2f a, float k)
{
    return Vector2f(0, 0);
}


Vector2f Math::Normalize(Vector2f a)
{
    Vector2f norm = a / Math::Magnitude(a);

    // cout << "Normalize (" << a.x << ", " << a.y << ") is (" << norm.x << ", " << norm.y << ")" << endl;

    return norm;
}

float Math::Length(Vector2f a)
{
    return 0;
}

float Math::Magnitude(Vector2f a)
{
    // cout << "Magnitude of (" << a.x << ", " << a.y << ") is " << sqrt(a.x * a.x + a.y * a.y) << endl;
    return sqrt(a.x * a.x + a.y * a.y);
}

Vector2f Math::Dot(Vector2f a, Vector2f b)
{
    return Vector2f(0, 0);
}

float Math::Cross(Vector2f a, Vector2f b)
{
    return 0;
}

float Math::AngleBetween(Vector2f a, Vector2f b)
{
    return 0;
}
