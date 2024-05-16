#ifndef TESTSCRIPT_CIRCLEMELEEAI_H
#define TESTSCRIPT_CIRCLEMELEEAI_H

#include "../BaseEnemyEntity.h"

class CircleMeleeAI : public BaseEnemyEntity {
private:
    void attack() override;
public:
    CircleMeleeAI(float shapeRadius, int priority);
    CircleMeleeAI(sf::Vector2<unsigned int> spawnPosition, float shapeRadius, int priority) : CircleMeleeAI(shapeRadius, priority) {
        this->spawnPosition = spawnPosition;
    }
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const override  {
        return std::make_unique<CircleMeleeAI>(spawnPosition, this->correctShape.getRadius(), this->priority);
    };
};

#endif //TESTSCRIPT_CIRCLEMELEEAI_H