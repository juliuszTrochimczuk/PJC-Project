#ifndef TESTSCRIPT_BULLET_H
#define TESTSCRIPT_BULLET_H

#include "../VisualEntity.h"

class Bullet : public VisualEntity {
private:
    sf::CircleShape correctShape;
    float speed;
    sf::Vector2<float> moveDirection;

    bool isBulletOnMap();
protected:
    int damage;

    void destroyBullet();
public:
    Bullet(sf::Vector2<unsigned int> spawnPos, float speed, int damage, sf::Vector2<float> moveDirection, int priority);
    void update() override;
};


#endif //TESTSCRIPT_BULLET_H