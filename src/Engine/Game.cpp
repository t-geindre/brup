#include "Game.h"
#include "Debug/CollisionMasks.h"
#include "Debug/FramePerSecond.h"

using namespace engine;

Game::Game() {
    drawPool = new DrawPool;
    updatePool = new UpdatePool;
    collisionPool = new CollisionPool;
    clock = new sf::Clock;
    eventDispatcher = new EventDispatcher;
}

void Game::init(std::string title) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window = new sf::RenderWindow(
            sf::VideoMode(1024, 768),
            title,
            sf::Style::Default,
            settings
            );

    window->setFramerateLimit(60);

    updatePool->push(collisionPool);
}

void Game::handleEvents() {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit = true;
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                quit = true;
            }
            if (debugEnabled) {
                switch (event.key.code) {
                    case sf::Keyboard::F1:
                        drawPool->toggle(debugObjects[0]);
                        break;
                    case sf::Keyboard::F2:
                        drawPool->toggle(debugObjects[1]);
                        break;
                }
            }
        }
    }
}

void Game::run() {
    while (!quit) {
        update();
        draw();
    }
    window->close(); // todo put it in a cleanup method
}

void Game::update() {
    updateElapsedTime();
    handleEvents();
    updatePool->update(this);
}

void Game::draw() {
    window->clear();
    drawPool->draw(getRenderTarget());
    window->display();
}

UpdatePool *Game::getUpdatePool() {
    return updatePool;
}

DrawPool *Game::getDrawPool() {
    return drawPool;
}

int Game::getElapsedTime() {
    return elapsedTime;
}

sf::RenderTarget *Game::getRenderTarget() {
    return window;
}

void Game::updateElapsedTime() {
    elapsedTime = clock->restart().asMilliseconds();
}

void Game::addObject(Initable *initable) {
    initable->init(this);
}

CollisionPool *Game::getCollisionPool() {
    return collisionPool;
}

void Game::enableDebug() {
    debugEnabled = true;

    this->debugObjects[0] = new CollisionMasks;
    this->addObject(this->debugObjects[0]);

    this->debugObjects[1] = new FramePerSecond;
    this->addObject(this->debugObjects[1]);
}

EventDispatcher *Game::getEventDispatcher() {
    return eventDispatcher;
}

void Game::destroy(GameObject *gameObject) {

}
