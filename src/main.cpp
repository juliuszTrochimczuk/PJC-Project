#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Player/Player.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Killer Bean");
    auto player = Player();
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            fmt::println("XDD");
        }
        window.clear(sf::Color::Black);
        window.draw(player.getShape());
        window.display();
    }
}
