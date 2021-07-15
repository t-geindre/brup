#include "CollisionPool.h"

using namespace engine;

CollisionPool::CollisionPool() {
    pool = new std::vector<Collidable*>;
}

void CollisionPool::update(Game *game) {
    for (int i = 0; i < pool->size(); i++) {
        Collidable *objA = (*pool)[i];
        CollisionMask maskA = objA->getCollisionMask();

        for (int j = i+1; j < pool->size(); j++) {
            Collidable *objB = (*pool)[i];
            CollisionMask maskB = objA->getCollisionMask();

            if (maskA.x < maskB.x + maskB.width &&
               maskA.x + maskA.width > maskB.x &&
               maskA.y < maskB.y + maskB.height &&
               maskA.height + maskA.y > maskB.y) {
                objA->CollisionWith(objB);
                objB->CollisionWith(objA);
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
