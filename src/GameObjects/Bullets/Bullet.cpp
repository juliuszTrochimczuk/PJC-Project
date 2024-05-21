#include "Bullet.h"
#include "../../GameControllers/GameController.h"

Bullet::Bullet(sf::Vector2<unsigned int> spawnPos, float speed, int damage, sf::Vector2<float> moveDirection, int priority) :
        VisualEntity(priority), speed(speed), damage(damage), moveDirection(moveDirection) {
    correctShape = sf::CircleShape(5);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius() / 2;
    correctShape.setOrigin(originPoint);
    shape = &correctShape;

    spawnPosition = spawnPos;
}

void Bullet::update() {
    if (GameController::getInstance()->getPlayer()->isDead) {
        bulletDeath();
        return;
    }
    shape->move(moveDirection * speed * GameController::getInstance()->getTimeController()->getDeltaTime());
    if (!isBulletOnMap()) {
        bulletDeath();
    }
}

bool Bullet::isBulletOnMap() {
    auto position = shape->getPosition();
    return (position.x >= GameController::getInstance()->getMap()->leftUppMapCorner.x and position.y >= GameController::getInstance()->getMap()->leftUppMapCorner.y
        and position.x <= GameController::getInstance()->getMap()->rightDownMapCorner.x and position.y <= GameController::getInstance()->getMap()->rightDownMapCorner.y);
}

void Bullet::bulletDeath() {
    priority = -50;
}