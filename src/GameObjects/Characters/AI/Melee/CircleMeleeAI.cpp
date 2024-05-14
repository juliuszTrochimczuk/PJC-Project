#include "CircleMeleeAI.h"
#include "../../../../GameControllers/GameController.h"
#include <fmt/core.h>

CircleMeleeAI::CircleMeleeAI(float shapeRadius, int priority) : BaseEnemyEntity(shapeRadius, priority) {
    health = 15;
    damage = 5;
    speed = 90.5f;
    maxDistanceToPlayer = 45.0f;
    interval = 1.4f;
}

void CircleMeleeAI::attack() {
    fmt::println("I'm melee atacking in aoe");
    GameController::getInstance()->player->takeDamage(damage);
}