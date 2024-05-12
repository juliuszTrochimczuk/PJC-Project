#pragma once

#ifndef PJC_PROJECT_MAP_H
#define PJC_PROJECT_MAP_H

#include "../VisualEntity.h"

class Map : public VisualEntity {
private:
    sf::RectangleShape correctShape;
public:
    sf::Vector2<float> mapSize = sf::Vector2<float>(1800, 900);
    sf::Vector2<float> leftUppMapCorner;
    sf::Vector2<float> rightDownMapCorner;
    Map(int priority);
    void start() override;
};

#endif //PJC_PROJECT_MAP_H
