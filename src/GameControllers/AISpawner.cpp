#include "AISpawner.h"
#include "GameController.h"
#include <random>
#include <fmt/core.h>

void AISpawner::spawnEnemies() {
    auto enemyIndex = MathMethods::drawRandomNumber(0, enemyPool.size());
    auto enemyPosition = drawEnemyPosition();
    auto newEnemy = (*(enemyPool[enemyIndex])).makeCopy(enemyPosition);
    GameController::getInstance()->addEnemyEntity(newEnemy.get());
    GameController::getInstance()->addVisualEntity(newEnemy.get());
    GameController::getInstance()->addBasicEntity(std::move(newEnemy));
}

void AISpawner::update() {
    auto appRunTime =  GameController::getInstance()->timeController->getApplicationRuntime();
    if (appRunTime - timeThatLastEnemyWasSpawned > interval and GameController::getInstance()->getEnemyEntities().size() < 1) {
        timeThatLastEnemyWasSpawned = appRunTime;
        spawnEnemies();
    }
}

sf::Vector2<unsigned int> AISpawner::drawEnemyPosition() {
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