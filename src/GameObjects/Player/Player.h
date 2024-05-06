#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H
#include "SFML/Graphics.hpp"
#include "../Character.h"
#include "../../GameController/MathMethods.h"

class Player : Character {
private:
    sf::Vector2<float> getInputVector();
public:
    Player();
    void moveCharacter();
};


#endif //PJC_PROJECT_PLAYER_H
