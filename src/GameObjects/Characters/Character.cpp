#include "Character.h"

Character::Character(float shapeRadius, int priority) : VisualEntity(priority) {
    correctShape = sf::CircleShape(shapeRadius);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius();
    correctShape.setOrigin(originPoint);
    shape = &correctShape;
}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        onDeath();
        priority = -100;
    }
}