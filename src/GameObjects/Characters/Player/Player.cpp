#include "Player.h"
#include "../../../GameControllers/GameController.h"
#include "SFML/Graphics.hpp"
#include "fmt/core.h"

Player::Player(float shapeRadius, int priority) : Character("Assets/Player/player.png", shapeRadius, priority) {
    spawnPosition = GameController::getInstance()->getGameWindow()->getSize();
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
    auto moveVector = getInputVector() * moveSpeed * GameController::getInstance()->getTimeController()->getDeltaTime();
    auto pos = shape->getPosition();
    if (pos.x < GameController::getInstance()->getMap()->leftUppMapCorner.x and moveVector.x < 0)
        moveVector.x = 0;
    else if (pos.x > GameController::getInstance()->getMap()->rightDownMapCorner.x and moveVector.x > 0)
        moveVector.x = 0;
    if (pos.y < GameController::getInstance()->getMap()->leftUppMapCorner.y and moveVector.y < 0)
        moveVector.y = 0;
    else if (pos.y > GameController::getInstance()->getMap()->rightDownMapCorner.y and moveVector.y > 0)
        moveVector.y = 0;
    shape->move(moveVector);
}

void Player::update() {
    if (!isDead) {
        moveCharacter();
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            revivePlayer();
    }
}

void Player::onDeath() {
    isDead = true;
}

void Player::takeXP() {
    currentXP += 10;
    if (currentXP >= xpBarrier) {
        levelUp();
        upgradeWeapon();
    }
}

void Player::levelUp() {
    currentXP = currentXP - xpBarrier;
    xpBarrier += (int)(xpBarrier * 1.5);
}

void Player::upgradeWeapon() {
    if (activeShootingPoints + 1 == possibleShootingPoints.size()) return;
    activeShootingPoints++;
    weapon->setShootingPoints(possibleShootingPoints[activeShootingPoints]);
}

void Player::healing(int amount) {
    health += amount;
    if (health > 100) health = 100;
}

void Player::revivePlayer() {
    isDead = false;
    health = 100;
    activeShootingPoints = 0;
    currentXP = 0;
    xpBarrier = 20;
    weapon->setShootingPoints(possibleShootingPoints[activeShootingPoints]);
    correctShape.setPosition(spawnPosition.x, spawnPosition.y);
}
