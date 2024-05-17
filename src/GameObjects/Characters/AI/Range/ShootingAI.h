#ifndef TESTSCRIPT_SHOOTINGAI_H
#define TESTSCRIPT_SHOOTINGAI_H

#include <utility>
#include "../BaseEnemyEntity.h"

class ShootingAI : public BaseEnemyEntity{
private:
    std::vector<sf::Vector2<float>> shootingDirections;
    float bulletSpeed;

    void attack() override;
public:
    ShootingAI(std::vector<sf::Vector2<float>> shootingDirections, float bulletSpeed, int health, int damage, float speed, float maxDistanceToPlayer,
               float intervalBetweenAction, float shapeRadius, int priority) :
            BaseEnemyEntity(health, damage, speed, maxDistanceToPlayer, intervalBetweenAction, shapeRadius, priority),
            shootingDirections(std::move(shootingDirections)), bulletSpeed(bulletSpeed) { };
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const override  {
        auto copy = std::make_unique<ShootingAI>(shootingDirections, bulletSpeed, health, damage, speed, maxDistanceToPlayer,
                                                 intervalBetweenAction, correctShape.getRadius(), priority);
        copy->spawnPosition = spawnPosition;
        return std::move(copy);
    };
};


#endif //TESTSCRIPT_SHOOTINGAI_H
