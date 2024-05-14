#ifndef TESTSCRIPT_AISPAWNER_H
#define TESTSCRIPT_AISPAWNER_H

#include <vector>
#include "../GameObjects/Characters/Character.h"
#include "../GameObjects/Characters/AI/BaseEnemyEntity.h"

class AISpawner : public BasicEntity {
private:
    float interval;
    float timeThatLastEnemyWasSpawned = 0;
    void spawnEnemies();
    sf::Vector2<unsigned int> drawEnemyPosition();
    std::vector<BaseEnemyEntity*> enemyPool;
public:
    AISpawner(float interval, std::vector<BaseEnemyEntity*>& enemyPool, int priority);
    void update() override;
};


#endif //TESTSCRIPT_AISPAWNER_H
