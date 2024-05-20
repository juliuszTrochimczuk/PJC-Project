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

    void shoot();
public:
    Weapon(std::vector<sf::Vector2<float>> shootingPoints, float interval, float bulletSpeed, int bulletDamage, int priority);
    std::unique_ptr<Weapon> makeCopy() {
        return std::make_unique<Weapon>(shootingPoints, interval, bulletSpeed, bulletDamage, priority);
    }
    void update() override;

};

#endif //TESTSCRIPT_WEAPON_H