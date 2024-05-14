#include "EnemyBullet.h"
#include "../../GameControllers/MathMethods.h"
#include "../../GameControllers/GameController.h"

void EnemyBullet::update() {
    Bullet::update();
    auto distanceToPlayer = MathMethods::vector2Distance(shape->getPosition(), GameController::getInstance()->player->getShape()->getPosition());
    if (distanceToPlayer < 10.5f) {
        GameController::getInstance()->player->takeDamage(damage);
    }
}