#include "TeleportingAI.h"
#include "../../../../GameControllers/GameController.h"

void TeleportingAI::attack() {
    GameController::getInstance()->getPlayer()->takeDamage(damage);
}

void TeleportingAI::takeDamage(int amount) {
    Character::takeDamage(amount);
    auto drawnedPos = drawNewPosition();
    shape->setPosition(drawnedPos.x, drawnedPos.y);
}

sf::Vector2<unsigned int> TeleportingAI::drawNewPosition() {
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

void TeleportingAI::onDeath() {
    BaseEnemyEntity::onDeath();
    GameController::getInstance()->bossOnArena = false;
}
