#ifndef PJC_PROJECT_MATHMETHODS_H
#define PJC_PROJECT_MATHMETHODS_H

#include <SFML/Graphics.hpp>

class MathMethods {
public:
    static float vector2Magnitude(sf::Vector2<float>& vec);
    static sf::Vector2<float> vector2Normalize(sf::Vector2<float>& vec);
    static int drawRandomNumber(int min, int max);
    static float vector2Distance(sf::Vector2<float> const& vec1, sf::Vector2<float> const& vec2);
};

#endif //PJC_PROJECT_MATHMETHODS_H
