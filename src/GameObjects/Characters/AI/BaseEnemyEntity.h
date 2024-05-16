#ifndef TESTSCRIPT_BASEENEMYENTITY_H
#define TESTSCRIPT_BASEENEMYENTITY_H

#include "../Character.h"
#include <fmt/core.h>
#include <memory>

class BaseEnemyEntity : public Character {
private:
    float timeLastMadeAttack = 0;
    float distanceToPlayer;

    void move();
protected:
    const int damage;
    const float speed;
    const float maxDistanceToPlayer;
    const float intervalBetweenAction;

    virtual bool canAttack() { return distanceToPlayer <= maxDistanceToPlayer; }
    virtual void attack() { }
public:
    BaseEnemyEntity(int health, int damage, float speed, float maxDistanceToPlayer, float intervalBetweenAction, float shapeRadius, int priority);
    virtual std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const = 0;
    void update() override;
    void onDeath() override;
};


#endif //TESTSCRIPT_BASEENEMYENTITY_H
