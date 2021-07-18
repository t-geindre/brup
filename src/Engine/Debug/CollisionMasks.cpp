#include "CollisionMasks.h"
#include "../Collision/Collidable.h"

void engine::CollisionMasks::draw(sf::RenderTarget *target) {
    std::vector<Collidable*>* poolVector = pool->getVector();

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color(255 , 0, 255, 100));
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color(200, 0, 255));

    for (int i = 0; i < poolVector->size(); i++) {
        CollisionMask mask = (*poolVector)[i]->getCollisionMask();
        rect.setPosition(mask.x, mask.y);
        rect.setSize(sf::Vector2f(mask.width, mask.height));
        target->draw(rect);
    }
}

unsigned int engine::CollisionMasks::getDrawPriority() {
    return 5000;
}

void engine::CollisionMasks::init(engine::Game *game) {
    pool = game->getCollisionPool();
    GameObject::init(game);
}
