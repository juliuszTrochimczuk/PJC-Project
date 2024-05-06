#include "GameController.h"
#include <fmt/core.h>


GameController* GameController::getIntance() {
    fmt::println("XDD");
    if (instance == nullptr)
        instance = new GameController();
    return instance;
}