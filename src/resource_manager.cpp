#include <iostream>

#include "random.hpp"
#include "resource_manager.hpp"

bool ResourceManager::loadTexture(std::string key, std::string filename) {
    sf::Texture texture;

    if (!texture.loadFromFile("res/img/" + filename)) {
        std::cout << "Error loading file \"" << filename << "\"!\n";
        return false;
    }

    texture_map[key] = texture;
    return true;
}

bool ResourceManager::loadSound(std::string key, std::string filename) {
    sf::SoundBuffer sound_buffer;

    if (!sound_buffer.loadFromFile("res/sound/" + filename)) {
        std::cout << "Error loading file \"" << filename << "\"!\n";
        return false;
    }

    sound_buffer_map[key] = sound_buffer;

    sound_map[key] = sf::Sound(sound_buffer_map[key]);

    return true;
}

bool ResourceManager::loadResources() {
    if (!loadTexture("ship", "jet_003.png")) return false;
    if (!loadTexture("alpha", "ship_001.png")) return false;
    if (!loadTexture("beta", "ship_002.png")) return false;
    if (!loadTexture("gamma", "ship_003.png")) return false;
    if (!loadTexture("delta", "ship_004.png")) return false;
    if (!loadTexture("epsilon", "ship_005.png")) return false;
    if (!loadTexture("zeta", "ship_006.png")) return false;

    if (!loadSound("death", "death2.wav")) return false;
    if (!loadSound("explosion", "explosion2.wav")) return false;
    if (!loadSound("hurt", "hurt5.wav")) return false;
    if (!loadSound("missile1", "missile3.wav")) return false;
    if (!loadSound("missile2", "missile5.wav")) return false;
    if (!loadSound("power-up", "power-up3.wav")) return false;
    if (!loadSound("shoot1", "shoot1.wav")) return false;
    if (!loadSound("shoot2", "shoot2.wav")) return false;
    if (!loadSound("shoot3", "shoot3.wav")) return false;
    if (!loadSound("shoot4", "shoot4.wav")) return false;
    if (!loadSound("testsong1", "music/testsong1.wav")) return false;

    return true;
}
