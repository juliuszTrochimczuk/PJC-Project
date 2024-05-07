#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Player/Player.h"
#include "GameController/GameController.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Killer Bean");
    auto entitiesInGame = std::vector<BasicEntity*>();
    auto player = Player();
    entitiesInGame.push_back(&player);
    GameController::getInstance()->setGameWindow(&window);
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
            window.draw(entity->getShape());
            entity -> Update();
        }
        window.display();
    }
    delete GameController::getInstance();
}
