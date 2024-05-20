#include "Spawner.h"
#include "GameController.h"
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

}

void Spawner::update() {
    auto appRunTime =  GameController::getInstance()->timeController->getApplicationRuntime();
    if (appRunTime - timeThatLastEnemyWasSpawned > enemyInterval and GameController::getInstance()->getEnemyEntities().size() < 5) {
        timeThatLastEnemyWasSpawned = appRunTime;
        spawnEnemies();
    }
    if (appRunTime - timeThatLastFruitWasSpawned > fruitInterval) {
        timeThatLastFruitWasSpawned = appRunTime;
        spawnFruit();
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