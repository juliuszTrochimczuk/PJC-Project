#include "BaseEnemyEntity.h"
#include "../../../GameControllers/GameController.h"

BaseEnemyEntity::BaseEnemyEntity(float shapeRadius, int priority) : Character(shapeRadius, priority) {
    shape->setFillColor(sf::Color::Red);
    this->shapeRadius = shapeRadius;
}

void BaseEnemyEntity::update() {
    distanceToPlayer = MathMethods::vector2Distance(shape->getPosition(), GameController::getInstance()->player->getShape()->getPosition());
    auto appRunTime = GameController::getInstance()->timeController->getApplicationRuntime();
    if (distanceToPlayer > maxDistanceToPlayer)
        move();
    if (appRunTime - timeLastMadeAttack > interval and canAttack()) {
        timeLastMadeAttack = appRunTime;
        attack();
    }
}

void BaseEnemyEntity::move() {
    auto directionToPlayer = GameController::getInstance()->player->getShape()->getPosition() - shape->getPosition();
    directionToPlayer = MathMethods::vector2Normalize(directionToPlayer);
    shape->move(directionToPlayer * speed * GameController::getInstance()->timeController->getDeltaTime());
}

void BaseEnemyEntity::onDeath() {
    fmt::println("ENEMY HAS DIED");
}

