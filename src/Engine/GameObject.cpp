#include "GameObject.h"

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
    delete this;
}
