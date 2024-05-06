#ifndef PJC_PROJECT_GAMECONTROLLER_H
#define PJC_PROJECT_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

class GameController {
private:
    static GameController* instance;
    GameController() = default;
public:
    int x = 4;
    sf::RenderWindow gameWindow;
    static GameController* getIntance();
};


#endif //PJC_PROJECT_GAMECONTROLLER_H
