#ifndef TESTSCRIPT_CIRCLEMELEEAI_H
#define TESTSCRIPT_CIRCLEMELEEAI_H

#include "../BaseEnemyEntity.h"

class CircleMeleeAI : public BaseEnemyEntity {
private:
    bool canAttack() override;
    void attack() override;
public:
    CircleMeleeAI(float shapeRadius, int priority);
    CircleMeleeAI(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) : CircleMeleeAI(copy.getShapeRadius(), copy.priority) {
        this->spawnPosition = spawnPosition;
    }
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) const override  {
        return std::make_unique<CircleMeleeAI>(spawnPosition, copy);
    };
};


#endif //TESTSCRIPT_CIRCLEMELEEAI_H
