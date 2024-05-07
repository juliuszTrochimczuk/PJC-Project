#include "Player.h"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <fmt/ranges.h>

Player::Player() {
    shape = sf::CircleShape(50);
    health = 100;
    moveSpeed = 1.5f;
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
    auto borderOfWorld = sf::Vector2<float>(720, 475);
    auto pos = shape.getPosition();
    if (pos.x < 0 and moveVector.x < 0) moveVector.x = 0;
    else if (pos.x > borderOfWorld.x and moveVector.x > 1) moveVector.x = 0;
    if (pos.y < 0 and moveVector.y < 0) moveVector.y = 0;
    else if (pos.y > borderOfWorld.y and moveVector.y > 1) moveVector.y = 0;
    shape.move(moveVector);
}

void Player::Update() {
    moveCharacter();
    auto pos = shape.getPosition();
    fmt::println("{}", pos.x);
    fmt::println("{}", pos.y);
}
