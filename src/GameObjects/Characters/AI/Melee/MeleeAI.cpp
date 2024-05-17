#include "MeleeAI.h"
#include "../../../../GameControllers/GameController.h"
#include <fmt/core.h>

void MeleeAI::attack() {
    GameController::getInstance()->player->takeDamage(damage);
}