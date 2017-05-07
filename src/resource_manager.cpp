#include <iostream>
#include "resource_manager.hpp"

bool ResourceManager::loadTexture(std::string key, std::string filename) {
    sf::Texture texture;

    if (!texture.loadFromFile("res/" + filename + ".png")) {
        std::cout << "Error loading file \"" << filename << "\"!\n";
        return false;
    }

    texture_map[key] = texture;
    return true;
}
