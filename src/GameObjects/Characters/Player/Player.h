#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H

#include "SFML/Graphics.hpp"
#include "../Character.h"
#include "../../BasicEntity.h"
#include "../../../GameControllers/MathMethods.h"
#include "Weapon.h"

class Player : public Character {
private:
    int xpBarrier = 20;
    int currentXP = 0;
    float moveSpeed;

    Weapon* weapon;
    std::vector<std::vector<sf::Vector2<float>>> possibleShootingPoints {
            { sf::Vector2<float>(0,-1) },
            { sf::Vector2<float>(0, -1), sf::Vector2<float>(0, 1) },
            { sf::Vector2<float>(1, 0), sf::Vector2<float>(-1, 0) },
            { sf::Vector2<float>(0, -1), sf::Vector2<float>(0, 1), sf::Vector2<float>(1, 0), sf::Vector2<float>(-1, 0) },
            { sf::Vector2<float>(1, -1), sf::Vector2<float>(-1, -1) },
            { sf::Vector2<float>(1, 1), sf::Vector2<float>(-1, 1) },
            { sf::Vector2<float>(1, -1), sf::Vector2<float>(-1, -1), sf::Vector2<float>(1, 1), sf::Vector2<float>(-1, 1) },
            { sf::Vector2<float>(0, -1), sf::Vector2<float>(0, 1), sf::Vector2<float>(1, 0), sf::Vector2<float>(-1, 0),
                    sf::Vector2<float>(1, -1), sf::Vector2<float>(-1, -1), sf::Vector2<float>(1, 1), sf::Vector2<float>(-1, 1) },
    };
    int activeShootingPoints = 0;

    sf::Vector2<float> getInputVector();
    void moveCharacter();
    void levelUp();
    void upgradeWeapon();
public:
    bool isDead = false;

    Player(float shapeRadius, int priority);
    void update() override;
    void onDeath() override;
    void revivePlayer();
    void takeXP();
    void healing(int amount);
    void setWeapon(Weapon* weapon) { this->weapon = weapon; }
    int getCurrentXP() const { return currentXP; }
    int getXPBarrier() const { return xpBarrier; }
};

#endif //PJC_PROJECT_PLAYER_H