#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
private:
public:
    float x, y;
    sf::Sprite sprite;

    Enemy();
    Enemy(float x, float y, sf::Sprite sprite);

    void setXY(float x, float y);
    float getX();
    float getY();
};

#endif
