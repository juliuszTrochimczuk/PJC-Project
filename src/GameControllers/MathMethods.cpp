#include "MathMethods.h"
#include <cmath>
#include <random>

float MathMethods::vector2Magnitude(sf::Vector2<float> &vec) {
    return pow((pow(vec.x, 2) + pow(vec.y, 2)), 0.5);
}

sf::Vector2<float> MathMethods::vector2Normalize(sf::Vector2<float> &vec) {
    return vec / vector2Magnitude(vec);
}

int MathMethods::drawRandomNumber(int min, int max) {
    return min + (rand() % max - min);
    //obtain a random number from hardware
    auto rd = std::random_device();
    //seed the generator
    auto seed = std::mt19937(rd());
    // define the range
    auto range = std::uniform_int_distribution<int>(min, max);
    return range(rd);
}