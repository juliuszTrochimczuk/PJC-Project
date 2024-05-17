#include "MeleeAI.h"
#include "../../../../GameControllers/GameController.h"
#include <fmt/core.h>

void MeleeAI::attack() {
    fmt::println("I'm melee atacking in aoe");
    GameController::getInstance()->player->takeDamage(damage);
}