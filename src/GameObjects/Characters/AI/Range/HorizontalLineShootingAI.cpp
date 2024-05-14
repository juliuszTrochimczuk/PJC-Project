#include "HorizontalLineShootingAI.h"

HorizontalLineShootingAI::HorizontalLineShootingAI(float shapeRadius, int priority) : BaseEnemyEntity(shapeRadius, priority) {
    health = 15;
    damage = 5;
    speed = 90.5f;
    maxDistanceToPlayer = 45.0f;
    interval = 1.4f;
}

void HorizontalLineShootingAI::attack() {
    BaseEnemyEntity::attack();
}


