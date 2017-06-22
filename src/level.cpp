#include "level.hpp"

Level::Level() {

}

void Level::initTestEnemies() {
    enemies.push_back(Enemy(20, 20));
    enemies.push_back(Enemy(120, 20));
    enemies.push_back(Enemy(220, 20));
    enemies.push_back(Enemy(320, 20));
    enemies.push_back(Enemy(420, 20));
    enemies.push_back(Enemy(520, 20));
}
