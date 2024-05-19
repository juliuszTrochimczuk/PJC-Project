#include <iostream>
#include "Player.h"
#include "../../../GameControllers/GameController.h"
#include "SFML/Graphics.hpp"
#include "fmt/core.h"

Player::Player(float shapeRadius, int priority) : Character(shapeRadius, priority) {
    auto texture = sf::Texture();
    if (texture.loadFromFile("Assets/Player/player.png")) {
        std::cout << texture.getSize().x;
        std::cout << texture.getSize().y;
        shape->setTexture(&texture);
        shape->setTextureRect(sf::IntRect(0, 0, 512, 512));
    }
    else shape->setFillColor(sf::Color::Green);

    spawnPosition = GameController::getInstance()->gameWindow->getSize();
    spawnPosition.x = spawnPosition.x / 2;
    spawnPosition.y = spawnPosition.y / 2;
    health = 100;
    moveSpeed = 135.5f;
}

sf::Vector2<float> Player::getInputVector() {
    auto inputVector = sf::Vector2<float>(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputVector.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputVector.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputVector.y = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputVector.y = 1;
    if (MathMethods::vector2Magnitude(inputVector) > 1)
        inputVector = MathMethods::vector2Normalize(inputVector);
    return inputVector;
}


void Player::moveCharacter() {
    auto moveVector = getInputVector() * moveSpeed * GameController::getInstance()->timeController->getDeltaTime();
    auto pos = shape->getPosition();
    if (pos.x < GameController::getInstance()->map->leftUppMapCorner.x and moveVector.x < 0)
        moveVector.x = 0;
    else if (pos.x > GameController::getInstance()->map->rightDownMapCorner.x and moveVector.x > 0)
        moveVector.x = 0;
    if (pos.y < GameController::getInstance()->map->leftUppMapCorner.y and moveVector.y < 0)
        moveVector.y = 0;
    else if (pos.y > GameController::getInstance()->map->rightDownMapCorner.y and moveVector.y > 0)
        moveVector.y = 0;
    shape->move(moveVector);
}

void Player::update() {
    moveCharacter();
}

void Player::onDeath() {
    fmt::println("PLAYER HAS DIED");
}

void Player::takeXP() {
    currentXP += 10;
    if (currentXP >= xpBarrier) {
        levelUp();
        chooseNewWeapon();
    }
}

void Player::levelUp() {
    currentXP = currentXP - xpBarrier;
    xpBarrier += (int)(xpBarrier * 1.5);
}

void Player::chooseNewWeapon() {
    fmt::println("Get new weapon");
}