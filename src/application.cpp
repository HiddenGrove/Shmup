#include "application.hpp"

Application::Application() {
    window.create(sf::VideoMode(800, 600), "shmup");

}

void Application::start() {
    while (window.isOpen()) {
         sf::Event event;
         while (window.pollEvent(event)) {
             if (event.type == sf::Event::Closed) window.close();
         }

         window.clear(sf::Color::Black);
         window.display();
    }
}
