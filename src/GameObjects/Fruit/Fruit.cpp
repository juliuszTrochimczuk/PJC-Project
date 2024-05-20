#include "Fruit.h"
#include "../../GameControllers/GameController.h"

Fruit::Fruit(sf::Vector2<unsigned int> spawnPos, int priority) : VisualEntity(priority) {
    spawnPosition = spawnPos;

    correctShape = sf::CircleShape(20);
    if (texture.loadFromFile("Assets/Fruit/healing_droplet.png")) {
        correctShape.setTexture(&texture);
        correctShape.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    } else fmt::println("Something went wrong");
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= correctShape.getRadius();
    correctShape.setOrigin(originPoint);
    shape = &correctShape;
}

void Fruit::update() {
    if (correctShape.getGlobalBounds().intersects(GameController::getInstance()->player->getShape()->getGlobalBounds())) {
        GameController::getInstance()->player->healing(10);
        GameController::getInstance()->fruitOnLevel = false;
        priority = -150;
    }
}