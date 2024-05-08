#include "Character.h"

Character::Character(float shapeRadius, int priority) : VisualEntity(priority) {
    correctShape = sf::CircleShape(shapeRadius);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius() / 2;
    correctShape.setOrigin(originPoint);
    shape = &correctShape;
}

void Character::start() {
    setSpawnPosition(spawnPosition);
    VisualEntity::start();
}
