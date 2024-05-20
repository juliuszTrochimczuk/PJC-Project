#include "Fruit.h"

Fruit::Fruit(int priority) : VisualEntity(priority) {
    correctShape = sf::CircleShape(10);
    if (texture.loadFromFile("Assets/Fruit/healing_droplet.png")) {
        correctShape.setTexture(&texture);
        correctShape.setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));
    } else fmt::println("Something went wrong");
}

void Fruit::update() {

}