#ifndef TESTSCRIPT_SHOOTINGAI_H
#define TESTSCRIPT_SHOOTINGAI_H

#include "../BaseEnemyEntity.h"

class ShootingAI : public BaseEnemyEntity{
private:
    std::vector<sf::Vector2<float>> shootingPoints;
    void attack() override;
public:
    ShootingAI(std::vector<sf::Vector2<float>> shootingPoints, float shapeRadius, int priority);
    ShootingAI(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) : ShootingAI(copy.(), copy.priority) {
        this->spawnPosition = spawnPosition;
    }
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition) const override  {
        return std::make_unique<ShootingAI>(spawnPosition, );
    };
};


#endif //TESTSCRIPT_SHOOTINGAI_H
