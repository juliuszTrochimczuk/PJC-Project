#include "Weapon.h"
#include "../../../GameControllers/GameController.h"
#include "../../Bullets/PlayerBullet.h"

Weapon::Weapon(std::vector<sf::Vector2<float>> shootingPoints, float interval, float bulletSpeed, int bulletDamage,
               int priority) : BasicEntity(priority), shootingPoints(shootingPoints), interval(interval), bulletSpeed(bulletSpeed),
               bulletDamage(bulletDamage) { }

void Weapon::update() {
    if (GameController::getInstance()->getPlayer()->isDead) return;
    auto appRunTime = GameController::getInstance()->getTimeController()->getApplicationRuntime();
    if (appRunTime - timeLastShoot > interval) {
        timeLastShoot = appRunTime;
        shoot();
    }
}

void Weapon::shoot() {
    auto const& playerShape = GameController::getInstance()->getPlayer()->getShape();
    for (auto& direction : shootingPoints) {
        auto spawnPosition = sf::Vector2<unsigned int>();
        spawnPosition.x = static_cast<unsigned int>(playerShape->getPosition().x);
        spawnPosition.y = static_cast<unsigned int>(playerShape->getPosition().y);
        auto bullet = std::make_unique<PlayerBullet>
                (spawnPosition, bulletSpeed, bulletDamage, direction, 60);
        GameController::getInstance()->addVisualEntity(bullet.get());
        GameController::getInstance()->addBasicEntity(std::move(bullet));
    }
}