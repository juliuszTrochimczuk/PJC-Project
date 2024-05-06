//
// Created by Juliusz Trochimczuk on 06.05.2024.
//

#ifndef PJC_PROJECT_MATHMETHODS_H
#define PJC_PROJECT_MATHMETHODS_H
#include <SFML/Graphics.hpp>

class MathMethods {
public:
    template <typename T>
    static T vector2Magnitude(sf::Vector2<T>& vec);

    template <typename T>
    static sf::Vector2<T> vector2Normalize(sf::Vector2<T>& vec);
};

#endif //PJC_PROJECT_MATHMETHODS_H
