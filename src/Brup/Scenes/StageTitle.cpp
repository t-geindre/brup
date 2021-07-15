#include "StageTitle.h"
#include "Playing.h"

using namespace brup::scenes;

void StageTitle::draw(sf::RenderTarget *target) {

    target->draw(background);
    target->draw(title);

    GameObject::draw(target);
}

void StageTitle::init(engine::Game *game) {
    background.setPosition(0, 0);
    background.setFillColor(sf::Color(255, 255, 255));

    font.loadFromFile("../assets/fonts/bitwise.ttf");

    title.setFont(font);
    title.setString("STAGE 1");
    title.setFillColor(sf::Color(255, 0, 0));
    title.setOutlineColor(sf::Color(0, 0, 0));
    title.setOutlineThickness(5);
    title.setCharacterSize(150);
    title.setPosition(10, 10);

    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);

    GameObject::init(game);
}

void StageTitle::update(engine::Game *game) {
    sf::Vector2f display = game->getRenderTarget()->getView().getSize();
    background.setSize(display);
    title.setPosition(sf::Vector2f(display.x/2.0f,display.y/2.0f));

    GameObject::update(game);

    displayTime -= game->getElapsedTime();

    if (displayTime <= 0) {
        game->addObject(new brup::scenes::Playing);
        destroy(game);
    }
}