#ifndef TESTSCRIPT_TELEPORTINGAI_H
#define TESTSCRIPT_TELEPORTINGAI_H

#include "../BaseEnemyEntity.h"

class TeleportingAI : public BaseEnemyEntity {
private:
    void attack() override;
    void takeDamage(int amount) override;
    void onDeath() override;
    sf::Vector2<unsigned int> drawNewPosition();
public:
    TeleportingAI(int health, int damage, float speed, float maxDistanceToPlayer,
            float intervalBetweenAction, std::string pathToTexture, float shapeRadius, int priority) :
            BaseEnemyEntity(health, damage, speed, maxDistanceToPlayer, intervalBetweenAction,
                            pathToTexture, shapeRadius, priority) { };
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const override  {
        auto copy = std::make_unique<TeleportingAI>(health, damage, speed, maxDistanceToPlayer, intervalBetweenAction,
                                              pathToTexture, correctShape.getRadius(), priority);
        copy->spawnPosition = spawnPosition;
        return std::move(copy);
    };
};

#endif //TESTSCRIPT_TELEPORTINGAI_H