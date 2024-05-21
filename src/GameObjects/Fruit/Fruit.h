#ifndef TESTSCRIPT_FRUIT_H
#define TESTSCRIPT_FRUIT_H

#include <SFML/Graphics.hpp>
#include "../VisualEntity.h"

class Fruit : public VisualEntity {
private:
    sf::Texture texture;
    sf::CircleShape correctShape;
public:
    Fruit(sf::Vector2<unsigned int> spawnPos, int priority);
    void update() override;
    void onDeath();
};


#endif //TESTSCRIPT_FRUIT_H