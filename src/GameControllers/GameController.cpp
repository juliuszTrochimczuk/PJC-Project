#include "GameController.h"
#include <algorithm>
#include <fmt/core.h>
#include <iostream>

GameController* GameController::instance = nullptr;

GameController* GameController::getInstance() {
    if (instance == nullptr)
        instance = new GameController();
    return instance;
}

void GameController::setGameFrameRate(int frameRate) const {
    gameWindow->setFramerateLimit(frameRate);
    timeController->setFrameRateForTimer(frameRate);
}

void GameController::refreshBasicEntities() {
    std::ranges::sort(basicEntities, std::ranges::greater(),
                      [](auto const& e) { return e->priority; });
}

void GameController::refreshVisualEntities() {
    std::ranges::sort(visualEntities, std::ranges::greater(),
                      [](auto const& ve) { return ve->priority; });
}

void GameController::refreshEnemyEntities() {
    std::ranges::sort(enemyEntities, std::ranges::greater(),
                      [](auto const& enemy) { return enemy->getHealth(); });
}

void GameController::addBasicEntity(std::unique_ptr<BasicEntity> newEntity) {
    basicEntitiesHolder.push_back(std::move(newEntity));
}

void GameController::addVisualEntity(VisualEntity* newVisualEntity) {
    visualEntitiesHolder.push_back(newVisualEntity);
}

void GameController::addEnemyEntity(BaseEnemyEntity* newEnemyEntity) {
    enemyEntitiesHolder.push_back(newEnemyEntity);
}

void GameController::addFromBasicHolderToVector() {
    for (auto& e : basicEntitiesHolder) {
        e->start();
        basicEntities.push_back(std::move(e));
    }
    basicEntitiesHolder.clear();
}

void GameController::addFromVisualHolderToVector() {
    for (auto& e : visualEntitiesHolder) {
        visualEntities.push_back(e);
    }
    visualEntitiesHolder.clear();
}

void GameController::addFromEnemyHolderToVector() {
    for (auto& e : enemyEntitiesHolder) {
        enemyEntities.push_back(e);
    }
    enemyEntitiesHolder.clear();
}

void GameController::refreshVectorsWithEntities() {
    refreshEnemyEntities();
    removeFromEnemyEntities();

    refreshVisualEntities();
    removeFromVisualEntities();

    refreshBasicEntities();
    removeFromBasicEntities();

    addFromBasicHolderToVector();
    refreshBasicEntities();

    addFromVisualHolderToVector();
    refreshVisualEntities();

    addFromEnemyHolderToVector();
    refreshEnemyEntities();
}

void GameController::removeFromBasicEntities() {
    if (basicEntities.size() == 0) return;
    auto bIter = basicEntities.size() - 1;
    while (basicEntities[bIter]-> priority < 0) {
        basicEntities.pop_back();
        bIter--;
    }
}

void GameController::removeFromVisualEntities() {
    if (visualEntities.size() == 0) return;
    auto vIter = visualEntities.size() - 1;
    while (visualEntities[vIter]->priority < 0) {
        visualEntities.pop_back();
        vIter--;
    }
}

void GameController::removeFromEnemyEntities() {
    if (enemyEntities.size() == 0) return;
    auto eIter = enemyEntities.size() - 1;
    while (enemyEntities.size() != 0 and enemyEntities[eIter] -> getHealth() < 1) {
        enemyEntities.pop_back();
        eIter--;
    }
}

