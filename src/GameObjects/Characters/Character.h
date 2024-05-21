#ifndef PJC_PROJECT_CHARACTER_H
#define PJC_PROJECT_CHARACTER_H

#include "SFML/Graphics.hpp"
#include "../BasicEntity.h"
#include "../VisualEntity.h"

class Character : public VisualEntity {
private:
    sf::Texture texture;
protected:
    int health;
    sf::CircleShape correctShape;
    Character(std::string pathToTexture, float shapeRadius, int priority);
public:
    int getHealth() const { return health; }
    virtual void takeDamage(int amount);
    virtual void onDeath();
};

#endif //PJC_PROJECT_CHARACTER_H