#include "GameController.h"
#include <algorithm>
#include <fmt/core.h>

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

void GameController::addEntityToBasicEntities(std::unique_ptr<BasicEntity> newEntity) {
    basicEntities.push_back(std::move(newEntity));
    refreshBasicEntities();
}

void GameController::addEntityToVisualEntities(VisualEntity* newVisualEntity) {
    visualEntities.push_back(newVisualEntity);
    refreshVisualEntities();
}

void GameController::addEntityToEnemyEntities(BaseEnemyEntity* newEnemyEntity) {
    enemyEntities.push_back(newEnemyEntity);
    refreshEnemyEntities();
}

void GameController::removeFromBasicEntities() {
    refreshBasicEntities();
    auto eIter = basicEntities.size() - 1;
    while (basicEntities[eIter]-> priority < 0) {
        basicEntities.pop_back();
        eIter--;
    }
}

void GameController::removeFromVisualEntities() {
    refreshVisualEntities();
    auto vIter = visualEntities.back();
    while (vIter-> priority < 0) {
        visualEntities.pop_back();
        vIter--;
    }
}

void GameController::removeFromEnemyEntities() {
    refreshEnemyEntities();
    auto enemyIter = enemyEntities.back();
    while (enemyIter->getHealth() < 1) {
        enemyEntities.pop_back();
        enemyIter--;
    }
}

