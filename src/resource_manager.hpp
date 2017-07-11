#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResourceManager {
public:
    ResourceManager();
    std::map<std::string, sf::Texture> texture_map;
    std::map<std::string, sf::SoundBuffer> sound_buffer_map;
    std::map<std::string, sf::Sound> sound_map;

    bool loadResources();
private:
    bool loadTexture(std::string key, std::string filename);
    bool loadSound(std::string key, std::string filename);
    bool createBackground(std::string key);
};

#endif
