#include "enemy.hpp"

Enemy::Enemy() {

}
    
Enemy::Enemy(float x, float y, sf::Sprite sprite) {

}

void Enemy::setXY(float x, float y) {
    this->x = x;
    this->y = y;
    sprite.setPosition(sf::Vector2f(x, y));
}

float Enemy::getX() { return x; }

float Enemy::getY() { return y; }
