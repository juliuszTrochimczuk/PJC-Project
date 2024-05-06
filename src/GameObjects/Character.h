#ifndef PJC_PROJECT_CHARACTER_H
#define PJC_PROJECT_CHARACTER_H

#include <SFML/Graphics.hpp>

class Character {
protected:
    sf::CircleShape shape;
    int health;
    float moveSpeed;
public:
    sf::CircleShape getShape();
};

#endif //PJC_PROJECT_CHARACTER_H