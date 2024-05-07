#ifndef PJC_PROJECT_PLAYER_H
#define PJC_PROJECT_PLAYER_H
#include "SFML/Graphics.hpp"
#include "../Character.h"
#include "../BasicEntity.h"
#include "../../GameController/MathMethods.h"

class Player : public Character {
private:
    sf::Vector2<float> getInputVector();
    void moveCharacter();
public:
    Player();
    void Update() override;
};


#endif //PJC_PROJECT_PLAYER_H
