#ifndef PJC_PROJECT_GAMECONTROLLER_H
#define PJC_PROJECT_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

class GameController {
private:
    static GameController* instance;
    GameController() = default;
public:
    sf::RenderWindow* gameWindow;
    static GameController* getInstance();
    void setGameWindow(sf::RenderWindow* gameWindow);
};


#endif //PJC_PROJECT_GAMECONTROLLER_H
