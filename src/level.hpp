#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include "enemy.hpp"

class Level {
private:
public:
    std::vector<Enemy> enemies;

    Level();
    void initTestEnemies();
};

#endif
