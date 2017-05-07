#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

class Application {
private:
    sf::RenderWindow window;
public:
    Application();
    void start();
    void draw();
    void input();
    void update();
    void handleEvents(sf::Event event);
};

#endif
