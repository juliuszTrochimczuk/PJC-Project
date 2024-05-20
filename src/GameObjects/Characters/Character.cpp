#include "Character.h"
#include "fmt/core.h"

Character::Character(std::string pathToTexture, float shapeRadius, int priority) : VisualEntity(priority) {
    correctShape = sf::CircleShape(shapeRadius);
    if (texture.loadFromFile(pathToTexture)) {
        correctShape.setTexture(&texture);
        correctShape.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    } else fmt::println("Something went wrong");
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius();
    correctShape.setOrigin(originPoint);
    shape = &correctShape;
}

void Character::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) {
        onDeath();
        priority = -100;
    }
}