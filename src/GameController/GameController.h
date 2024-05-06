//
// Created by Juliusz Trochimczuk on 06.05.2024.
//

#ifndef PJC_PROJECT_GAMECONTROLLER_H
#define PJC_PROJECT_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>

class GameController {
private:
    static GameController* instance;
public:
    sf::RenderWindow& gameWindow;
    GameController(sf::RenderWindow& window): gameWindow(window) { }
};


#endif //PJC_PROJECT_GAMECONTROLLER_H
