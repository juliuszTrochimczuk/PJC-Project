#include "MathMethods.h"
#include <cmath>

template<typename T>
T MathMethods::vector2Magnitude(sf::Vector2<T> &vec) {
    return pow((pow(vec.x, 2) + pow(vec.y, 2)), 0.5);
}

template<typename T>
sf::Vector2<T> MathMethods::vector2Normalize(sf::Vector2<T> &vec) {
    return vec / vector2Magnitude(vec);
}
