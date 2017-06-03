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

void Application::start() {
    rm.loadTexture("ship", "jet_003.png");
    rm.loadTexture("alpha", "ship_001.png");
    rm.loadTexture("beta", "ship_002.png");
    rm.loadTexture("gamma", "ship_003.png");

    rm.loadSound("death", "death2.wav");
    rm.loadSound("explosion", "explosion2.wav");
    rm.loadSound("hurt", "hurt5.wav");
    rm.loadSound("missile1", "missile3.wav");
    rm.loadSound("missile2", "missile5.wav");
    rm.loadSound("power-up", "power-up3.wav");
    rm.loadSound("shoot1", "shoot1.wav");
    rm.loadSound("shoot2", "shoot2.wav");
    rm.loadSound("shoot3", "shoot3.wav");
    rm.loadSound("shoot4", "shoot4.wav");
    rm.loadSound("testsong1", "music/testsong1.wav");

    ship.x = WIDTH / 2 - 32;
    ship.y = HEIGHT - 64;
    ship.sprite.setTexture(rm.texture_map["ship"]);
    ship.speed = 0.5;

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    Enemy a;
    a.setXY(20, 20);
    a.sprite.setTexture(rm.texture_map["alpha"]);

    Enemy b;
    b.setXY(120, 20);
    b.sprite.setTexture(rm.texture_map["beta"]);

    Enemy c;
    c.setXY(220, 20);
    c.sprite.setTexture(rm.texture_map["gamma"]);

    lvl.enemies.push_back(a);
    lvl.enemies.push_back(b);
    lvl.enemies.push_back(c);

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

    /*
    rm.loadSound("power-up", "power-up3");
    rm.loadSound("shoot1", "shoot1");
    rm.loadSound("shoot2", "shoot2");
    rm.loadSound("shoot3", "shoot3");
    rm.loadSound("shoot4", "shoot4");
    */
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
