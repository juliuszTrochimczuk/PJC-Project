#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "SFML/Graphics.hpp"
#include "../Character.h"
#include "../../BasicEntity.h"
#include "../../../GameControllers/MathMethods.h"

class Player : public Character {
private:
    int xpBarrier;
    int currentXP;
    float moveSpeed;

    sf::Vector2<float> getInputVector();
    void moveCharacter();
    void levelUp();
    void chooseNewWeapon();
public:
    Player(float shapeRadius, int priority);
    void update() override;
    void onDeath() override;
    void takeXP();
};

#endif //PJC_PROJECT_PLAYER_H