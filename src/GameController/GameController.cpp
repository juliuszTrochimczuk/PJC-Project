#include "GameController.h"

GameController* GameController::instance = nullptr;

GameController* GameController::getInstance() {
    if (instance == nullptr)
        instance = new GameController();
    return instance;
}

void GameController::setGameWindow(sf::RenderWindow *gameWindow) {
    this->gameWindow = gameWindow;
}
