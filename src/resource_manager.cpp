#include <iostream>
#include "resource_manager.hpp"

bool ResourceManager::loadTexture(std::string key, std::string filename) {
    sf::Texture texture;

    if (!texture.loadFromFile("res/img/" + filename + ".png")) {
        std::cout << "Error loading file \"" << filename << "\"!\n";
        return false;
    }

    texture_map[key] = texture;
    return true;
}

bool ResourceManager::loadSound(std::string key, std::string filename) {
    sf::SoundBuffer sound_buffer;

    if (!sound_buffer.loadFromFile("res/sound/" + filename + ".wav")) {
        std::cout << "Error loading file \"" << filename << "\"!\n";
        return false;
    }

    sound_buffer_map[key] = sound_buffer;

    sound_map[key] = sf::Sound(sound_buffer_map[key]);

    return true;
}
