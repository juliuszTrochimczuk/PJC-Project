#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObjects/Characters/Player/Player.h"
#include "GameControllers/GameController.h"
#include "GameObjects/Map/Map.h"
#include "GameControllers/AISpawner.h"

void HandleEvents(sf::RenderWindow &window) {
    auto event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::Resized) {
            auto area = sf::FloatRect(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(area));
        }
    }
}

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(1920, 1001), "Killer Bean");
    GameController::getInstance()->setGameWindow(&window);

    auto timeController = std::make_unique<TimeController>(101);
    GameController::getInstance()->setTimeController(timeController.get());

    auto player = std::make_unique<Player>(25, 99);
    GameController::getInstance()->setPlayer(player.get());

    auto map = std::make_unique<Map>(100);
    GameController::getInstance()->setMap(map.get());

    auto baseEnemyEntity = BaseEnemyEntity(80);
    auto enemyPool = std::vector<BaseEnemyEntity*> {
        &baseEnemyEntity
    };
    auto aiSpawner = std::make_unique<AISpawner>(1.2f, enemyPool, 90);

    GameController::getInstance()->setGameFrameRate(240);

    GameController::getInstance()->addEntityToVisualEntities(player.get());
    GameController::getInstance()->addEntityToVisualEntities(map.get());

    GameController::getInstance()->addEntityToBasicEntities(std::move(timeController));
    GameController::getInstance()->addEntityToBasicEntities(std::move(player));
    GameController::getInstance()->addEntityToBasicEntities(std::move(map));
    GameController::getInstance()->addEntityToBasicEntities(std::move(aiSpawner));

    while (window.isOpen()) {
        HandleEvents(window);

        window.clear(sf::Color::Black);

        for (auto& entity : GameController::getInstance()->getBasicEntities()) {
            if (entity -> canDoStart())
                entity->start();
        }

        for (auto& entity : GameController::getInstance()->getBasicEntities()) {
            entity->update();
        }

        for (auto &entity : GameController::getInstance()->getVisualEntities()) {
            window.draw(*(entity->getShape()));
        }

        window.display();
    }
    GameController::getInstance()->removeAllEnemyEntities();
    GameController::getInstance()->removeAllVisualEntities();
    GameController::getInstance()->removeAllBasicEntities();
    delete GameController::getInstance();
}