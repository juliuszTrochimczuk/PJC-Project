#include "PlayerBullet.h"
#include "../../GameControllers/GameController.h"

void PlayerBullet::update() {
    Bullet::update();
    for (auto const& enemy : GameController::getInstance()->getEnemyEntities()) {
        if (shape->getGlobalBounds().intersects(enemy->getShape()->getGlobalBounds())) {
            bulletDeath();
            enemy->takeDamage(damage);
        }
    }
}