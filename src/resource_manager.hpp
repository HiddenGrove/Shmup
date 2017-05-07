#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class ResourceManager {
public:
    std::map<std::string, sf::Texture> texture_map;

    bool loadTexture(std::string key, std::string filename);
};

#endif
