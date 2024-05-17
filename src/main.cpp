#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Characters/Player/Player.h"
#include "GameObjects/Characters/AI/Melee/MeleeAI.h"
#include "GameControllers/GameController.h"
#include "GameObjects/Map/Map.h"
#include "GameControllers/AISpawner.h"
#include "GameObjects/Characters/AI/Range/ShootingAI.h"

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

    auto timeController = std::make_unique<TimeController>(120);
    GameController::getInstance()->setTimeController(timeController.get());

    auto map = std::make_unique<Map>(110);
    GameController::getInstance()->setMap(map.get());

    auto meleeAI = MeleeAI(15, 5, 90.5f, 45.0f, 1.4f, 15, 80);
    auto shootingAI1 = ShootingAI(std::vector<sf::Vector2<float>> {
        sf::Vector2<float>(-1, 0),
        sf::Vector2<float>(1, 0)
        },115.5f, 30, 8, 55.8f, 350.0f, 2.0f, 30, 80);
    auto enemyPool = std::vector<BaseEnemyEntity*> {
            &meleeAI,
            &shootingAI1
    };
    auto aiSpawner = std::make_unique<AISpawner>(0.01f, enemyPool, 95);

    auto player = std::make_unique<Player>(25, 90);
    GameController::getInstance()->setPlayer(player.get());

    GameController::getInstance()->setGameFrameRate(60);

    GameController::getInstance()->addVisualEntity(player.get());
    GameController::getInstance()->addVisualEntity(map.get());

    GameController::getInstance()->addBasicEntity(std::move(timeController));
    GameController::getInstance()->addBasicEntity(std::move(player));
    GameController::getInstance()->addBasicEntity(std::move(map));
    GameController::getInstance()->addBasicEntity(std::move(aiSpawner));

    while (window.isOpen()) {
        HandleEvents(window);

        window.clear(sf::Color::Black);

        GameController::getInstance()->refreshVectorsWithEntities();

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