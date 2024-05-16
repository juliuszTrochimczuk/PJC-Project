#include <fmt/core.h>
#include "ShootingAI.h"
#include "../../../Bullets/EnemyBullet.h"
#include "../../../../GameControllers/GameController.h"

void ShootingAI::attack() {
    for (auto& direction : shootingDirections) {
        auto spawnPosition = sf::Vector2<unsigned int>();
        spawnPosition.x = static_cast<unsigned int>(shape->getPosition().x);
        spawnPosition.y = static_cast<unsigned int>(shape->getPosition().y);
        auto bullet = std::make_unique<EnemyBullet>
                (spawnPosition, bulletSpeed, damage, direction, 70);
        GameController::getInstance()->addVisualEntity(bullet.get());
        GameController::getInstance()->addBasicEntity(std::move(bullet));
    }
    fmt::println("I'm shooting now");
}