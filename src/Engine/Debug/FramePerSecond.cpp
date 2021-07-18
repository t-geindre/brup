#include "FramePerSecond.h"
#include "../Game.h"

using namespace engine;

void FramePerSecond::init(Game *game) {
    font.loadFromFile("../assets/fonts/arial.ttf");

    display.setFont(font);
    display.setCharacterSize(20);
    display.setPosition(5, 1);
    display.setFillColor(sf::Color::Yellow);
    display.setOutlineThickness(2);
    display.setOutlineColor(sf::Color::Black);

    GameObject::init(game);
}

void FramePerSecond::draw(sf::RenderTarget *target) {
    display.setString(std::to_string(fps));
    target->draw(display);

    GameObject::draw(target);
}

unsigned int FramePerSecond::getDrawPriority() {
    return 5000;
}

void FramePerSecond::update(Game *game) {
    float currentTime = game->getElapsedTime();
    fps = 1000.f / currentTime;
    lastTime = currentTime;
}

