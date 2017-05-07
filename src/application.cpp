#include "application.hpp"
#include "ship.hpp"

Application::Application() {
    window.create(sf::VideoMode(800, 600), "shmup");
}

void Application::start() {
    // turn into resource manager
    sf::Texture ship_texture;
    if (!ship_texture.loadFromFile("res/ship.png")) {
        window.close();
    }

    sf::Sprite ship_sprite;
    ship_sprite.setTexture(ship_texture);

    Ship ship(0, 0, ship_sprite);


    while (window.isOpen()) {
         sf::Event event;

         while (window.pollEvent(event)) {
             handleEvents(event);
         }

         window.clear(sf::Color::Black);
         window.draw(ship.sprite);
         window.display();
    }
}

void Application::draw() {

}

void Application::update() {
    
}

void Application::input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    
    }
}

void Application::handleEvents(sf::Event event) {
    if (event.type == sf::Event::Closed) window.close();

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) window.close();
    }
}
