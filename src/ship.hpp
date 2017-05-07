#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics.hpp>

class Ship {
private:
public:
    int x, y;
    sf::Sprite sprite;

    Ship(int x, int y, sf::Sprite sprite);
};

#endif
