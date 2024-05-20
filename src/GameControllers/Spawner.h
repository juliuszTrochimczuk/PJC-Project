#ifndef TESTSCRIPT_SPAWNER_H
#define TESTSCRIPT_SPAWNER_H

#include <vector>
#include "../GameObjects/Characters/Character.h"
#include "../GameObjects/Characters/AI/BaseEnemyEntity.h"

class Spawner : public BasicEntity {
private:
    float fruitInterval;
    float enemyInterval;
    float timeThatLastEnemyWasSpawned = 0;
    float timeThatLastFruitWasSpawned = 0;
    void spawnEnemies();
    void spawnFruit();
    sf::Vector2<unsigned int> drawPositionOnMap();
    std::vector<BaseEnemyEntity*> enemyPool;
public:
    Spawner(float fruitInterval, float enemyInterval, std::vector<BaseEnemyEntity*>& enemyPool, int priority) :
        BasicEntity(priority), enemyInterval(enemyInterval), fruitInterval(fruitInterval), enemyPool(enemyPool) { };
    void update() override;
};

#endif //TESTSCRIPT_SPAWNER_H