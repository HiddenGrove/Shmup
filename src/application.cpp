#include "application.hpp"
#include "level.hpp"
#include "ship.hpp"
#include "enemy.hpp"

Application::Application() {
    window.create(sf::VideoMode(WIDTH, HEIGHT), "shmup");
    window.setKeyRepeatEnabled(false);
    // use input() for repeating keys, update() for non-repeating keys
}

Ship ship;
Level lvl;
sf::Sprite background;

void Application::start() {
    rm.loadResources();
    rm.loadSpaceBackground(WIDTH, HEIGHT);

    background.setTexture(rm.texture_map["background"]);

    ship.x = WIDTH / 2 - 32;
    ship.y = HEIGHT - 64;
    ship.sprite.setTexture(rm.texture_map["ship"]);
    ship.speed = 0.5;

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);
    
    lvl.initTestEnemies();
    lvl.enemies[0].sprite.setTexture(rm.texture_map["alpha"]);
    lvl.enemies[1].sprite.setTexture(rm.texture_map["beta"]);
    lvl.enemies[2].sprite.setTexture(rm.texture_map["gamma"]);
    lvl.enemies[3].sprite.setTexture(rm.texture_map["delta"]);
    lvl.enemies[4].sprite.setTexture(rm.texture_map["epsilon"]);
    lvl.enemies[5].sprite.setTexture(rm.texture_map["zeta"]);

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
    window.draw(background);
    window.draw(ship.sprite);
    for (Enemy e : lvl.enemies) {
        window.draw(e.sprite);
    }
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
        if (event.key.code == sf::Keyboard::F2) takeScreenshot();
        if (event.key.code == sf::Keyboard::Num1) rm.sound_map["death"].play();
        if (event.key.code == sf::Keyboard::Num2) rm.sound_map["explosion"].play();
        if (event.key.code == sf::Keyboard::Num3) rm.sound_map["hurt"].play();
        if (event.key.code == sf::Keyboard::Num4) rm.sound_map["missile1"].play();
        if (event.key.code == sf::Keyboard::Num5) rm.sound_map["missile2"].play();
        if (event.key.code == sf::Keyboard::Num6) rm.sound_map["power-up"].play();
        if (event.key.code == sf::Keyboard::Num7) rm.sound_map["shoot1"].play();
        if (event.key.code == sf::Keyboard::Num8) rm.sound_map["shoot2"].play();
        if (event.key.code == sf::Keyboard::Num9) rm.sound_map["shoot3"].play();
        if (event.key.code == sf::Keyboard::Num0) rm.sound_map["shoot4"].play();
        if (event.key.code == sf::Keyboard::Z) rm.sound_map["testsong1"].play();
    }
}

void Application::takeScreenshot() {
    sf::Vector2u windowSize = window.getSize();
    sf::Texture texture;
    texture.create(windowSize.x, windowSize.y);
    texture.update(window);
    sf::Image screenshot = texture.copyToImage();
    screenshot.saveToFile("screenshot.png");
}
