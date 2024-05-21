#include "BaseEnemyEntity.h"
#include "../../../GameControllers/GameController.h"

BaseEnemyEntity::BaseEnemyEntity(int health, int damage, float speed, float maxDistanceToPlayer, float intervalBetweenAction,
                                 std::string pathToTexture, float shapeRadius, int priority) : Character(pathToTexture, shapeRadius, priority), damage(damage),
                                 speed(speed), maxDistanceToPlayer(maxDistanceToPlayer), intervalBetweenAction(intervalBetweenAction), pathToTexture(pathToTexture) {
    this->health = health;
}

void BaseEnemyEntity::update() {
    if (GameController::getInstance()->getPlayer()->isDead) {
        Character::onDeath();
        return;
    }
    distanceToPlayer = MathMethods::vector2Distance(shape->getPosition(), GameController::getInstance()->getPlayer()->getShape()->getPosition());
    auto appRunTime = GameController::getInstance()->getTimeController()->getApplicationRuntime();
    if (distanceToPlayer > maxDistanceToPlayer)
        move();
    if (appRunTime - timeLastMadeAttack > intervalBetweenAction and canAttack()) {
        timeLastMadeAttack = appRunTime;
        attack();
    }
}

void BaseEnemyEntity::move() {
    auto directionToPlayer = GameController::getInstance()->getPlayer()->getShape()->getPosition() - shape->getPosition();
    directionToPlayer = MathMethods::vector2Normalize(directionToPlayer);
    shape->move(directionToPlayer * speed * GameController::getInstance()->getTimeController()->getDeltaTime());
}

void BaseEnemyEntity::onDeath() {
    Character::onDeath();
    GameController::getInstance()->getPlayer()->takeXP();
}