#include "ShootingAI.h"

ShootingAI::ShootingAI(std::vector<sf::Vector2<float>> shootingPoints,float shapeRadius, int priority) :
BaseEnemyEntity(shapeRadius, priority), shootingPoints(shootingPoints) {
    health = 15;
    damage = 5;
    speed = 90.5f;
    maxDistanceToPlayer = 45.0f;
    interval = 1.4f;
}

void ShootingAI::attack() {
    BaseEnemyEntity::attack();
}


