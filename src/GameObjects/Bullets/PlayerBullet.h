#ifndef TESTSCRIPT_PLAYERBULLET_H
#define TESTSCRIPT_PLAYERBULLET_H

#include "Bullet.h"

class PlayerBullet : public Bullet {
public:
    PlayerBullet(sf::Vector2<unsigned int> spawnPos, float speed, int damage, sf::Vector2<float> moveDirection, int priority) :
        Bullet(spawnPos, speed, damage, moveDirection, priority) {
        auto color = sf::Color(0, 255, 0); //Aqua Green
        shape->setFillColor(color);
    };
    void update() override;
};

#endif //TESTSCRIPT_PLAYERBULLET_H