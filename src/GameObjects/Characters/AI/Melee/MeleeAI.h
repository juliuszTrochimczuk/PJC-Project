#ifndef TESTSCRIPT_MELEEAI_H
#define TESTSCRIPT_MELEEAI_H

#include "../BaseEnemyEntity.h"

class MeleeAI : public BaseEnemyEntity {
private:
    void attack() override;
public:
    MeleeAI(int health, int damage, float speed, float maxDistanceToPlayer,
            float intervalBetweenAction, std::string pathToTexture, float shapeRadius, int priority) :
                  BaseEnemyEntity(health, damage, speed, maxDistanceToPlayer, intervalBetweenAction,
                                  pathToTexture, shapeRadius, priority) { };
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const override  {
        auto copy = std::make_unique<MeleeAI>(health, damage, speed, maxDistanceToPlayer, intervalBetweenAction,
                                              pathToTexture, correctShape.getRadius(), priority);
        copy->spawnPosition = spawnPosition;
        return std::move(copy);
    };
};

#endif //TESTSCRIPT_MELEEAI_H