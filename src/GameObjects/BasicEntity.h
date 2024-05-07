#ifndef PJC_PROJECT_BASICENTITY_H
#define PJC_PROJECT_BASICENTITY_H

#include <SFML/Graphics.hpp>

class BasicEntity {
public:
    sf::CircleShape shape;
public:
    virtual void Start() { };
    virtual void Update() { };
    sf::CircleShape getShape() { return shape; }
};

#endif //PJC_PROJECT_BASICENTITY_H