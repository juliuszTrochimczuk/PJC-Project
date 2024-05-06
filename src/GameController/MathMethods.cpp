#include "MathMethods.h"
#include <cmath>

float MathMethods::vector2Magnitude(sf::Vector2<float> &vec) {
    return pow((pow(vec.x, 2) + pow(vec.y, 2)), 0.5);
}

sf::Vector2<float> MathMethods::vector2Normalize(sf::Vector2<float> &vec) {
    return vec / vector2Magnitude(vec);
}