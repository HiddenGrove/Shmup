#include "level.hpp"

Level::Level() {

}

void Level::initTestEnemies() {
    Enemy a;
    a.setXY(20, 20);
    enemies.push_back(a);
    Enemy b;
    b.setXY(120, 20);
    enemies.push_back(b);
    Enemy c;
    c.setXY(220, 20);
    enemies.push_back(c);
}
