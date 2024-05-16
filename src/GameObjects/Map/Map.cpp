#include "Map.h"
#include "../../GameControllers/GameController.h"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>

Map::Map(int priority) : VisualEntity(priority) {
    correctShape = sf::RectangleShape(sf::Vector2f(mapSize.x, mapSize.y));
    auto size = correctShape.getSize();
    size.x /= 2;
    size.y /= 2;
    correctShape.setOrigin(size);
    spawnPosition = GameController::getInstance()->gameWindow->getSize();
    spawnPosition.x = spawnPosition.x / 2;
    spawnPosition.y = spawnPosition.y / 2;
    shape = &correctShape;
}

void Map::start() {
    VisualEntity::start();
    auto screenSize = sf::Vector2<float>(GameController::getInstance()->gameWindow->getSize());
    auto centerPointOfScreen = screenSize;
    centerPointOfScreen.x /= 2;
    centerPointOfScreen.y /= 2;

    leftUppMapCorner.x = centerPointOfScreen.x - (mapSize.x / 2);
    leftUppMapCorner.y = centerPointOfScreen.y - (mapSize.y / 2);

    rightDownMapCorner.x = mapSize.x;
    rightDownMapCorner.y = mapSize.y;
}
