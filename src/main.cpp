#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Player/Player.h"
#include "GameController/GameController.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(1920, 1001), "Killer Bean");
    window.setFramerateLimit(60);
    GameController::getInstance()->setGameWindow(&window);
    auto entitiesInGame = std::vector<BasicEntity*>();
    auto player = Player();
    entitiesInGame.push_back(&player);
    for (auto& entity : entitiesInGame) {
        entity -> Start();
    }
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                auto area = sf::FloatRect(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(area));
            }
        }
        window.clear(sf::Color::Black);
        for (auto& entity : entitiesInGame) {
            entity -> Update();
            window.draw(entity->getShape());
        }
        window.display();
    }
    delete GameController::getInstance();
}