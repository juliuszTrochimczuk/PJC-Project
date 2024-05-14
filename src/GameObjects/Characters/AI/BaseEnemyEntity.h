#ifndef TESTSCRIPT_BASEENEMYENTITY_H
#define TESTSCRIPT_BASEENEMYENTITY_H

#include "../Character.h"
#include <fmt/core.h>
#include <memory>

class BaseEnemyEntity : public Character {
private:
    float timeLastMadeAttack = 0;
    float shapeRadius;

    void move();
protected:
    float damage;
    float speed;
    float maxDistanceToPlayer;
    float distanceToPlayer;
    float interval;

    virtual bool canAttack() { return true; }
    virtual void attack() { }
public:
    BaseEnemyEntity(float shapeRadius, int priority);
    virtual std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) const = 0;
    void update() override;
    void onDeath() override;
    float getShapeRadius() const { return shapeRadius; }
};


#endif //TESTSCRIPT_BASEENEMYENTITY_H
