#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "resource_manager.hpp"
#include <SFML/Graphics.hpp>

class Application {
private:
    sf::RenderWindow window;
public:
    const int WIDTH = 800;
    const int HEIGHT = 640;
    ResourceManager rm;

    Application();
    void start();
    void draw();
    void input();
    void update();
    void handleEvents(sf::Event event);
    void takeScreenshot();
};

#endif
