#include "GameObject.h"
#include "Game.h"
using namespace engine;

void GameObject::draw(sf::RenderTarget *target) {

}

void GameObject::init(Game *game) {
    game->getDrawPool()->push(this);
    game->getUpdatePool()->push(this);
}

void GameObject::update(Game *game) {

}

void GameObject::destroy(Game *game) {
    game->getDrawPool()->remove(this);
    game->getUpdatePool()->remove(this);
    for (int i = 0; i < listeners.size(); i++) {
        game->getEventDispatcher()->removeListener(listeners[i]);
    }
    delete this;
}

unsigned int GameObject::getDrawPriority() {
    return 0;
}

sf::Vector2f GameObject::getPosition() {
    return position;
}

sf::Vector2f GameObject::getSize() {
    return size;
}

void GameObject::setPosition(sf::Vector2f position) {
    this->position = position;
}

void GameObject::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void GameObject::setSize(sf::Vector2f size) {
    this->size = size;
}

void GameObject::setSize(float x, float y) {
    size.x = x;
    size.y = y;
}
