#include "CollisionPool.h"
#include "Collidable.h"

using namespace engine;

CollisionPool::CollisionPool() {
    pool = new std::vector<Collidable*>;
}

void CollisionPool::update(Game *game) {
    for (int i = 0; i < pool->size(); i++) {
        Collidable *objA = (*pool)[i];
        CollisionMask maskA = objA->getCollisionMask();

        for (int j = i+1; j < pool->size(); j++) {
            Collidable *objB = (*pool)[j];
            CollisionMask maskB = objB->getCollisionMask();

            if (maskA.x < (maskB.x + maskB.width) && (maskA.x + maskA.width) > maskB.x &&
                maskA.y < (maskB.y + maskB.height) && (maskA.height + maskA.y) > maskB.y) {

                objA->collisionWith(objB, game);
                objB->collisionWith(objA, game);
            }
        }
    }
}

void CollisionPool::push(Collidable *collidable) {
    pool->push_back(collidable);
}

void CollisionPool::remove(Collidable *collidable) {
    for (int i = 0; i < pool->size(); i++) {
        if ((*pool)[i] == collidable) {
            pool->erase(pool->begin()+i);
            return;
        }
    }
}

void CollisionPool::clear() {
    pool->clear();
}

void CollisionPool::draw(sf::RenderTarget *target) {
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color(0, 0, 255, 100));
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color(200, 0, 255));

    for (int i = 0; i < pool->size(); i++) {
        CollisionMask mask = (*pool)[i]->getCollisionMask();
        rect.setPosition(mask.x, mask.y);
        rect.setSize(sf::Vector2f(mask.width, mask.height));
        target->draw(rect);
    }
}
