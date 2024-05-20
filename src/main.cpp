#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Characters/Player/Player.h"
#include "GameObjects/Characters/AI/Melee/MeleeAI.h"
#include "GameControllers/GameController.h"
#include "GameObjects/Map/Map.h"
#include "GameControllers/Spawner.h"
#include "GameObjects/Characters/AI/Range/ShootingAI.h"
#include "GameObjects/Characters/Player/Weapon.h"

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

    auto meleeAI = MeleeAI(10, 5, 90.5f, 45.0f, 1.4f, "Assets/Enemies/Melee_Enemy.png",20, 80);
    auto shootingAI1 = ShootingAI(std::vector<sf::Vector2<float>> {
        sf::Vector2<float>(-1, 0),
        sf::Vector2<float>(1, 0)
        },115.5f, 15, 8, 55.8f, 350.0f, 2.0f, "Assets/Enemies/Line_Enemy.png",25, 80);
    auto shootingAI2 = ShootingAI(std::vector<sf::Vector2<float>> {
            sf::Vector2<float>(0, -1),
            sf::Vector2<float>(0, 1)
    },115.5f, 15, 8, 55.8f, 350.0f, 2.0f, "Assets/Enemies/Line_Enemy.png",25, 80);
    auto shootingAI3 = ShootingAI(std::vector<sf::Vector2<float>> {
            sf::Vector2<float>(0, -1),
            sf::Vector2<float>(0, 1),
            sf::Vector2<float>(-1, 0),
            sf::Vector2<float>(1, 0),
    },115.5f, 25, 8, 55.8f, 425.0f, 2.0f, "Assets/Enemies/Plus_Enemy.png", 35, 80);
    auto enemyPool = std::vector<BaseEnemyEntity*> {
            &meleeAI,
            &shootingAI1,
            &shootingAI2,
            &shootingAI3
    };
    auto aiSpawner = std::make_unique<Spawner>(0.01f, enemyPool, 95);

    auto player = std::make_unique<Player>(25, 90);
    GameController::getInstance()->setPlayer(player.get());

    auto startingWeapon = std::make_unique<Weapon>(std::vector<sf::Vector2<float>> {
       sf::Vector2<float>(0, -1)
    }, 1, 150.0f, 5, 60);

    GameController::getInstance()->setGameFrameRate(60);

    GameController::getInstance()->addVisualEntity(player.get());
    GameController::getInstance()->addVisualEntity(map.get());

    GameController::getInstance()->addBasicEntity(std::move(timeController));
    GameController::getInstance()->addBasicEntity(std::move(player));
    GameController::getInstance()->addBasicEntity(std::move(map));
    GameController::getInstance()->addBasicEntity(std::move(aiSpawner));
    GameController::getInstance()->addBasicEntity(std::move(startingWeapon));

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