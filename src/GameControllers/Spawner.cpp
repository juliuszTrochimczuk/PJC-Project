#include "Spawner.h"
#include "GameController.h"
#include "../GameObjects/Fruit/Fruit.h"
#include <fmt/core.h>

void Spawner::spawnEnemies() {
    auto enemyIndex = MathMethods::drawRandomNumber(0, enemyPool.size() - 1);
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

void Spawner::spawnBoss() {
    auto enemyPosition = drawPositionOnMap();
    auto newBoss = (*(enemyPool[enemyPool.size() - 1])).makeCopy(enemyPosition);
    GameController::getInstance()->addEnemyEntity(newBoss.get());
    GameController::getInstance()->addVisualEntity(newBoss.get());
    GameController::getInstance()->addBasicEntity(std::move(newBoss));
    GameController::getInstance()->bossOnArena = true;
}

void Spawner::update() {
    if (GameController::getInstance()->getPlayer()->isDead) {
        enemyTimer = 0;
        bossTimer = 0;
        fruitTimer = 0;
        return;
    }
    if (GameController::getInstance()->getEnemyEntities().size() < 5) {
        enemyTimer += GameController::getInstance()->getTimeController()->getDeltaTime();
        if (enemyTimer > enemyInterval) {
            enemyTimer = 0.0f;
            spawnEnemies();
        }
    }
    if (!GameController::getInstance()->bossOnArena) {
        bossTimer += GameController::getInstance()->getTimeController()->getDeltaTime();
        if (bossTimer > bossInterval) {
            bossTimer = 0.0f;
            spawnBoss();
        }
    }
    if (!GameController::getInstance()->fruitOnLevel) {
        fruitTimer += GameController::getInstance()->getTimeController()->getDeltaTime();
        if (fruitTimer > fruitInterval) {
            fruitTimer = 0.0f;
            spawnFruit();
        }
    }
}

sf::Vector2<unsigned int> Spawner::drawPositionOnMap() {
    auto pos = sf::Vector2<unsigned int>();
    pos.x = MathMethods::drawRandomNumber(
        GameController::getInstance()->getMap()->leftUppMapCorner.x,
        GameController::getInstance()->getMap()->rightDownMapCorner.x
    );
    pos.y = MathMethods::drawRandomNumber(
            GameController::getInstance()->getMap()->leftUppMapCorner.y,
            GameController::getInstance()->getMap()->rightDownMapCorner.y
    );
    return pos;
}
