#pragma once

#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "SFML/Graphics.hpp"
#include "../Character.h"
#include "../../BasicEntity.h"
#include "../../../GameControllers/MathMethods.h"

class Player : public Character {
private:
    sf::Vector2<float> leftUpperMapCorner;
    sf::Vector2<float> rightDownMapCorner;
    sf::Vector2<float> getInputVector();
    void moveCharacter();
public:
    void update() override;
    Player(float shapeRadius, int priority);
};

#endif //PJC_PROJECT_PLAYER_H
