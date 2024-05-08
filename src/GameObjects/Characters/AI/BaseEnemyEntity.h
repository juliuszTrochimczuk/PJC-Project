#ifndef TESTSCRIPT_BASEENEMYENTITY_H
#define TESTSCRIPT_BASEENEMYENTITY_H


#include "../Character.h"
#include <fmt/core.h>

class BaseEnemyEntity : public Character {
private:
public:
    BaseEnemyEntity(int priority) : Character(30, priority) {
        shape->setFillColor(sf::Color::Red);
        this->health = 30;
    };
    BaseEnemyEntity(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const &copy) :
                    Character(30, copy.priority) {
        shape->setFillColor(sf::Color::Red);
        this->health = copy.getHealth();
        this->spawnPosition = spawnPosition;
    };
};


#endif //TESTSCRIPT_BASEENEMYENTITY_H
