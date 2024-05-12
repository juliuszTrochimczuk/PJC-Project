#pragma once

#ifndef PJC_PROJECT_CHARACTER_H
#define PJC_PROJECT_CHARACTER_H

#include "SFML/Graphics.hpp"
#include "../BasicEntity.h"
#include "../VisualEntity.h"

class Character : public VisualEntity {
protected:
    int health;
    float moveSpeed;
    sf::CircleShape correctShape;
    sf::Vector2<unsigned int> spawnPosition;
    Character(float shapeRadius, int priority);
public:
    int getHealth() const { return health; }
    void start() override;
};

#endif //PJC_PROJECT_CHARACTER_H