#ifndef TESTSCRIPT_HORIZONTALLINESHOOTINGAI_H
#define TESTSCRIPT_HORIZONTALLINESHOOTINGAI_H

#include "../BaseEnemyEntity.h"

class HorizontalLineShootingAI : public BaseEnemyEntity{
private:
    std::vector<sf::Vector2<float>> shootingPoints;
    void attack() override;
public:
    HorizontalLineShootingAI(float shapeRadius, int priority);
    HorizontalLineShootingAI(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) : HorizontalLineShootingAI(copy.getShapeRadius(), copy.priority) {
        this->spawnPosition = spawnPosition;
    }
    std::unique_ptr<BaseEnemyEntity> makeCopy(sf::Vector2<unsigned int> spawnPosition, BaseEnemyEntity const& copy) const override  {
        return std::make_unique<HorizontalLineShootingAI>(spawnPosition, copy);
    };
};


#endif //TESTSCRIPT_HORIZONTALLINESHOOTINGAI_H
