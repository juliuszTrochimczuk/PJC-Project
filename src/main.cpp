#include <fmt/core.h>
#include <SFML/Graphics.hpp>

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Killer Bean");
    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
