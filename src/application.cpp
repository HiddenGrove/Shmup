#include "application.hpp"
#include "ship.hpp"

Application::Application() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "shmup");
}

Ship ship;

void Application::start() {
    rm.loadTexture("ship", "spaceship");

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
        if (ship.x - ship.speed < 0) ship.x = 0;
        else ship.x -= ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (ship.x + 64 + ship.speed > WIDTH) ship.x = WIDTH - 64;
        else ship.x += ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (ship.y - ship.speed < 0) ship.y = 0;
        else ship.y -= ship.speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (ship.y + 64 + ship.speed > HEIGHT) ship.y = HEIGHT - 64;
        else ship.y += ship.speed;
    }

    ship.sprite.setPosition(sf::Vector2f(ship.x, ship.y));
}

void Application::handleEvents(sf::Event event) {
    if (event.type == sf::Event::Closed) window.close();

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) window.close();
    }
}
