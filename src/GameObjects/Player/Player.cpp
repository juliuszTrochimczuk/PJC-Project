#include "Player.h"
#include "../../GameController/GameController.h"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>

Player::Player() {
    shape = sf::CircleShape(25);
    auto originPoint = sf::Vector2<float>(1, 1);
    originPoint *= shape.getRadius() / 2;
    shape.setOrigin(originPoint);
    auto spawnPosition = GameController::getInstance()->gameWindow->getSize();
    spawnPosition.x = spawnPosition.x / 2 - shape.getOrigin().x;
    spawnPosition.y = spawnPosition.y / 2 - shape.getOrigin().y;
    shape.setPosition(spawnPosition.x, spawnPosition.y);
    health = 100;
    moveSpeed = 4.5f;
}

sf::Vector2<float> Player::getInputVector() {
    auto inputVector = sf::Vector2<float>(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputVector.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputVector.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputVector.y = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputVector.y = 1;
    MathMethods::vector2Normalize(inputVector);
    return inputVector;
}


void Player::moveCharacter() {
    auto moveVector = getInputVector() * moveSpeed;
    auto borderOfWorld = sf::Vector2<float>(GameController::getInstance()->gameWindow->getSize());
    auto safeArea = sf::Vector2<float>(100, 100);
    borderOfWorld -= safeArea;
    auto pos = shape.getPosition();
    if (pos.x < safeArea.x and moveVector.x < 0) moveVector.x = 0;
    else if (pos.x > borderOfWorld.x and moveVector.x > 0) moveVector.x = 0;
    if (pos.y < safeArea.y and moveVector.y < 0) moveVector.y = 0;
    else if (pos.y > borderOfWorld.y and moveVector.y > 0) moveVector.y = 0;
    shape.move(moveVector);
}

void Player::Update() {
    moveCharacter();
}
