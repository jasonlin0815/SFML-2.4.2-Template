#include "util.h"
#include "setting.h"
#include "math.h"

Vector2f Util::limit(Vector2f a, float l)
{
    float mag = Math::Magnitude(a);
    if (mag > MAX_SPEED)
    {
        float ratio = MAX_SPEED / mag;
        a *= ratio;
    }

    return a;
}