#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include "UI.h"
#include "../../GameControllers/GameController.h"

UI::UI(int priority) : BasicEntity(priority) {
    font.loadFromFile("Assets/UI/arial.ttf");

    heartIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    if (heartTexture.loadFromFile("Assets/UI/heart_icon.png")) {
        heartIcon.setTexture(&heartTexture);
        heartIcon.setTextureRect(sf::IntRect(0, 0, 240, 210));
    } else fmt::println("Something went wrong");
    healthText.setCharacterSize(32);
    healthText.setFont(font);
    healthText.setFillColor(sf::Color::Magenta);
    healthText.setString("100");
    healthText.setPosition(120, 25);

    xpIcon = sf::RectangleShape(sf::Vector2f(100, 100));
    xpIcon.setPosition(0, 100);
    if (xpTexture.loadFromFile("Assets/UI/xp-icon.png")) {
        xpIcon.setTexture(&xpTexture);
        xpIcon.setTextureRect(sf::IntRect(0, 0, 512, 512));
    }
    xpText.setCharacterSize(32);
    xpText.setFont(font);
    xpText.setFillColor(sf::Color::Magenta);
    xpText.setString("0%");
    xpText.setPosition(120, 125);

    reviveText.setString("");
    reviveText.setCharacterSize(50);
    reviveText.setFont(font);
    reviveText.setFillColor(sf::Color::Magenta);
    reviveText.setPosition(500, GameController::getInstance()->getGameWindow()->getSize().y / 2);
}

void UI::update() {
    healthText.setString(std::to_string(GameController::getInstance()->getPlayer()->getHealth()));

    auto xpPercentInFloat = (float)GameController::getInstance()->getPlayer()->getCurrentXP() / (float)GameController::getInstance()->getPlayer()->getXPBarrier();
    xpPercentInFloat *= 100;
    int xpPercent = xpPercentInFloat;
    xpText.setString(std::to_string(xpPercent) + "%");

    if (GameController::getInstance()->getPlayer()->isDead) {
        reviveText.setString("Press SPACE to start again");
    }
    else {
        reviveText.setString("");
    }
}

void UI::drawUI() {
    GameController::getInstance()->getGameWindow()->draw(heartIcon);
    GameController::getInstance()->getGameWindow()->draw(healthText);
    GameController::getInstance()->getGameWindow()->draw(xpIcon);
    GameController::getInstance()->getGameWindow()->draw(xpText);
    GameController::getInstance()->getGameWindow()->draw(reviveText);
}