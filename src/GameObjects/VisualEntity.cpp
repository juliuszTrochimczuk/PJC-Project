#include "VisualEntity.h"
#include "../GameControllers/GameController.h"
#include <fmt/core.h>

void VisualEntity::start() {
    BasicEntity::start();
    shape->setPosition(spawnPosition.x, spawnPosition.y);
}

sf::Shape* VisualEntity::getShape() {
    return shape;
}
