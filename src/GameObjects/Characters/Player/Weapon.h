#ifndef TESTSCRIPT_WEAPON_H
#define TESTSCRIPT_WEAPON_H

#include <memory>
#include "../../VisualEntity.h"

class Weapon : public BasicEntity {
private:
    std::vector<sf::Vector2<float>> shootingPoints;
    float interval;
    float timeLastShoot = 0;
    float bulletSpeed;
    int bulletDamage;
public:
    Weapon(std::vector<sf::Vector2<float>> shootingPoints, float interval, float bulletSpeed, int bulletDamage, int priority);
    void update() override;
    void shoot();
    void setShootingPoints(std::vector<sf::Vector2<float>> shootingPoints) { this->shootingPoints = shootingPoints; }
};

#endif //TESTSCRIPT_WEAPON_H