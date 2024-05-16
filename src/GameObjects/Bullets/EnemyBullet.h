#ifndef TESTSCRIPT_ENEMYBULLET_H
#define TESTSCRIPT_ENEMYBULLET_H

#include "Bullet.h"

class EnemyBullet : public Bullet {
public:
    EnemyBullet(sf::Vector2<unsigned int> spawnPos, float speed, int damage, sf::Vector2<float> moveDirection, int priority) :
        Bullet(spawnPos, speed, damage, moveDirection, priority) { };
    void update() override;
};


#endif //TESTSCRIPT_ENEMYBULLET_H
