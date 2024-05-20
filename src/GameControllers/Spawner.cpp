#include "Spawner.h"
#include "GameController.h"
#include "../GameObjects/Fruit/Fruit.h"
#include <fmt/core.h>

void Spawner::spawnEnemies() {
    auto enemyIndex = MathMethods::drawRandomNumber(0, enemyPool.size());
    auto enemyPosition = drawPositionOnMap();
    auto newEnemy = (*(enemyPool[enemyIndex])).makeCopy(enemyPosition);
    GameController::getInstance()->addEnemyEntity(newEnemy.get());
    GameController::getInstance()->addVisualEntity(newEnemy.get());
    GameController::getInstance()->addBasicEntity(std::move(newEnemy));
}

void Spawner::spawnFruit() {
    auto newFruit = std::make_unique<Fruit>(drawPositionOnMap(), 25);
    GameController::getInstance()->addVisualEntity(newFruit.get());
    GameController::getInstance()->addBasicEntity(std::move(newFruit));
    GameController::getInstance()->fruitOnLevel = true;
}

void Spawner::update() {
    if (GameController::getInstance()->getEnemyEntities().size() < 5) {
        enemyTimer += GameController::getInstance()->timeController->getDeltaTime();
        if (enemyTimer > enemyInterval) {
            enemyTimer = 0.0f;
            spawnEnemies();
        }
    }
    if (!GameController::getInstance()->fruitOnLevel) {
        fruitTimer += GameController::getInstance()->timeController->getDeltaTime();
        if (fruitTimer > fruitInterval) {
            fruitTimer = 0.0f;
            spawnFruit();
        }
    }
}

sf::Vector2<unsigned int> Spawner::drawPositionOnMap() {
    auto pos = sf::Vector2<unsigned int>();
    pos.x = MathMethods::drawRandomNumber(
        GameController::getInstance()->map->leftUppMapCorner.x,
        GameController::getInstance()->map->rightDownMapCorner.x
    );
    pos.y = MathMethods::drawRandomNumber(
            GameController::getInstance()->map->leftUppMapCorner.y,
            GameController::getInstance()->map->rightDownMapCorner.y
    );
    return pos;
}