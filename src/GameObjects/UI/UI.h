#ifndef TESTSCRIPT_UI_H
#define TESTSCRIPT_UI_H


#include "../BasicEntity.h"

class UI : public BasicEntity {
private:
    sf::Font font;

    sf::Texture heartTexture;
    sf::RectangleShape heartIcon;
    sf::Text healthText;

    sf::Texture xpTexture;
    sf::RectangleShape xpIcon;
    sf::Text xpText;

    sf::Text reviveText;
public:
    UI(int priority);
    void update() override;
    void drawUI();
};


#endif //TESTSCRIPT_UI_H
