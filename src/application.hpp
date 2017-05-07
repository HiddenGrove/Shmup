#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

class Application {
private:
    sf::RenderWindow window;
public:
    Application();
    void start();
};

#endif
