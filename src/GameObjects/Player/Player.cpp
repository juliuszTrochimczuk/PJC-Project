#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player() {
    shape = sf::CircleShape(50);
    health = 100;
    moveSpeed = 7.5f;
}

sf::Vector2<float> Player::getInputVector() {
    auto inputVector = sf::Vector2f();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) inputVector.x = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) inputVector.x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) inputVector.y = -1;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) inputVector.y = 1;
    return MathMethods::vector2Normalize(inputVector);
}


void Player::moveCharacter() {
    auto moveVector = getInputVector() * moveSpeed;
    shape.move(moveVector);
}
