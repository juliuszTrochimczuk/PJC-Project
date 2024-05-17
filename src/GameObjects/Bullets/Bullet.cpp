#include "Bullet.h"
#include "../../GameControllers/GameController.h"

Bullet::Bullet(sf::Vector2<unsigned int> spawnPos, float speed, int damage, sf::Vector2<float> moveDirection, int priority) :
        VisualEntity(priority), speed(speed), damage(damage), moveDirection(moveDirection) {
    correctShape = sf::CircleShape(5);
    correctShape.setFillColor(sf::Color::Blue);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius() / 2;
    correctShape.setOrigin(originPoint);
    shape = &correctShape;

    spawnPosition = spawnPos;
}

void Bullet::update() {
    shape->move(moveDirection * speed * GameController::getInstance()->timeController->getDeltaTime());
    if (!isBulletOnMap()) {
        priority = -50;
    }
}

void Bullet::destroyBullet() {
    fmt::println("BULLET DESTROY");
}

bool Bullet::isBulletOnMap() {
    auto position = shape->getPosition();
    return (position.x >= GameController::getInstance()->map->leftUppMapCorner.x and position.y <= GameController::getInstance()->map->leftUppMapCorner.y
        and position.x <= GameController::getInstance()->map->rightDownMapCorner.x and position.y >= GameController::getInstance()->map->leftUppMapCorner.y);
}