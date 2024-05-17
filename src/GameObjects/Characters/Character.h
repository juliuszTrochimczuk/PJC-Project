#ifndef PJC_PROJECT_CHARACTER_H
#define PJC_PROJECT_CHARACTER_H

#include "SFML/Graphics.hpp"
#include "../BasicEntity.h"
#include "../VisualEntity.h"

class Character : public VisualEntity {
protected:
    int health;
    sf::CircleShape correctShape;
    Character(float shapeRadius, int priority);
public:
    int getHealth() const { return health; }
    void takeDamage(int amount);
    virtual void onDeath() = 0;
};

#endif //PJC_PROJECT_CHARACTER_H