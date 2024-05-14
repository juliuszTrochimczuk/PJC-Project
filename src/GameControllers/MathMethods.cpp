#include "MathMethods.h"
#include <cmath>

float MathMethods::vector2Magnitude(sf::Vector2<float> &vec) {
    return (float)pow((pow(vec.x, 2) + pow(vec.y, 2)), 0.5);
}

sf::Vector2<float> MathMethods::vector2Normalize(sf::Vector2<float> &vec) {
    return vec / vector2Magnitude(vec);
}

int MathMethods::drawRandomNumber(int min, int max) {
    return min + (rand() % max - min);
}

float MathMethods::vector2Distance(sf::Vector2<float> const &vec1, sf::Vector2<float> const &vec2) {
    return (float)pow(pow(vec1.x-vec2.x, 2) + pow(vec1.y - vec2.y, 2), 0.5);
}
