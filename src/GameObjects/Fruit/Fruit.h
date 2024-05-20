#ifndef TESTSCRIPT_FRUIT_H
#define TESTSCRIPT_FRUIT_H

#include <SFML/Graphics.hpp>
#include "../VisualEntity.h"

class Fruit : public VisualEntity {
private:
    sf::Texture texture;
    sf::CircleShape correctShape;
public:
    Fruit(int priority);
    void update() override;
};


#endif //TESTSCRIPT_FRUIT_H