#include "Map.h"
#include "../../GameControllers/GameController.h"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>

Map::Map(int priority) : VisualEntity(priority) {
    correctShape = sf::RectangleShape(sf::Vector2f(mapSize.x, mapSize.y));
    if (texture.loadFromFile("Assets/Map/map.jpg")) {
        correctShape.setTexture(&texture);
        correctShape.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    } else fmt::println("Something went wrong");
    auto origin = correctShape.getSize();
    origin.x /= 2;
    origin.y /= 2;
    correctShape.setOrigin(origin);
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
