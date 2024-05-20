#include "EnemyBullet.h"
#include "../../GameControllers/MathMethods.h"
#include "../../GameControllers/GameController.h"

void EnemyBullet::update() {
    Bullet::update();
    if (shape->getGlobalBounds().intersects(GameController::getInstance()->player->getShape()->getGlobalBounds())) {
        bulletDeath();
        GameController::getInstance()->player->takeDamage(damage);
    }
}