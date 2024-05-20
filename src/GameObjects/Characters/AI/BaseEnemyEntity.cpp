#include "BaseEnemyEntity.h"
#include "../../../GameControllers/GameController.h"

BaseEnemyEntity::BaseEnemyEntity(int health, int damage, float speed, float maxDistanceToPlayer, float intervalBetweenAction,
                                 float shapeRadius, int priority) : Character(shapeRadius, priority), damage(damage),
                                 speed(speed), maxDistanceToPlayer(maxDistanceToPlayer), intervalBetweenAction(intervalBetweenAction) {
    shape->setFillColor(sf::Color::Red);
    this->health = health;
}

void BaseEnemyEntity::update() {
    distanceToPlayer = MathMethods::vector2Distance(shape->getPosition(), GameController::getInstance()->player->getShape()->getPosition());
    auto appRunTime = GameController::getInstance()->timeController->getApplicationRuntime();
    if (distanceToPlayer > maxDistanceToPlayer)
        move();
    if (appRunTime - timeLastMadeAttack > intervalBetweenAction and canAttack()) {
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
    GameController::getInstance()->player->takeXP();
}