#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

class Ship {
private:
public:
    float x, y;
    float speed;
    sf::Sprite sprite;

    Ship();
    Ship(float x, float y, float speed, sf::Sprite sprite);
};

#endif
