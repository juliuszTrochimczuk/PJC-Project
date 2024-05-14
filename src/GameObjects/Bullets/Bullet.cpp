#include "Bullet.h"
#include "../../GameControllers/GameController.h"

Bullet::Bullet(int priority, sf::Vector2<unsigned int> spawnPos,float speed, int damage, sf::Vector2<float> moveDirection) : VisualEntity(priority) {
    this->speed = speed;
    this->damage = damage;
    this->moveDirection = moveDirection;

    correctShape = sf::CircleShape(5);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius() / 2;
    correctShape.setOrigin(originPoint);

    setSpawnPosition(spawnPos);
}

void Bullet::update() {
    shape->move(moveDirection * speed * GameController::getInstance()->timeController->getDeltaTime());
}

void Bullet::destroyBullet() {
    fmt::println("BULLET DESTROY");
}