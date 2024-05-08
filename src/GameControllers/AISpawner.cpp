#include "AISpawner.h"
#include "GameController.h"
#include <random>
#include <fmt/core.h>

AISpawner::AISpawner(float interval, std::vector<BaseEnemyEntity *> &enemyPool, int priority) : BasicEntity(priority) {
    this->interval = interval;
    this->enemyPool = enemyPool;
}

void AISpawner::spawnEnemies() {
    auto enemyIndex = MathMethods::drawRandomNumber(0, enemyPool.size());
    auto enemyPosition = drawEnemyPosition();
    auto newEnemy = std::make_unique<BaseEnemyEntity>(enemyPosition, *enemyPool[enemyIndex]);
    GameController::getInstance()->addEntityToEnemyEntities(newEnemy.get());
    GameController::getInstance()->addEntityToVisualEntities(newEnemy.get());
    GameController::getInstance()->addEntityToBasicEntities(std::move(newEnemy));
}

void AISpawner::update() {
    auto appRunTime =  GameController::getInstance()->timeController->getApplicationRuntime();
    if (appRunTime - timeThatLastEnemyWasSpawned > interval) {
        fmt::println("Spawn time");
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