#include "application.hpp"
#include "ship.hpp"

Application::Application() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "shmup");
}

Ship ship;

void Application::start() {
    rm.loadTexture("ship", "ship");

    ship.x = WIDTH / 2 - 32;
    ship.y = HEIGHT - 64;
    ship.sprite.setTexture(rm.texture_map["ship"]);
    ship.speed = 0.5;

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    while (window.isOpen()) {
         sf::Event event;

         while (window.pollEvent(event)) {
             handleEvents(event);
         }

         while (accumulator > ups) {
             accumulator -= ups;
             update();
         }

         input();
         draw();

         accumulator += clock.restart();

    }
}

void Application::draw() {
    window.clear(sf::Color::Black);
    window.draw(ship.sprite);
    window.display();
}

void Application::update() {

}

void Application::input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        ship.x -= ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        ship.x += ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        ship.y -= ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        ship.y += ship.speed;
    }

    ship.sprite.setPosition(sf::Vector2f(ship.x, ship.y));
}

void Application::handleEvents(sf::Event event) {
    if (event.type == sf::Event::Closed) window.close();

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) window.close();
    }
}
