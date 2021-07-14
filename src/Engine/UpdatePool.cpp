#include "UpdatePool.h"
#include "Game.h"

using namespace engine;

UpdatePool::UpdatePool() {
    pool = new std::vector<Updatable*>;
}

void UpdatePool::push(Updatable *updatable) {
    pool->push_back(updatable);
}

void UpdatePool::remove(Updatable *updatable) {
    for (int i = 0; i < pool->size(); i++) {
        if ((*pool)[i] == updatable) {
            pool->erase(pool->begin()+i);
            return;
        }
    }
}

void UpdatePool::update(Game *game) {
    for (int i = 0; i < pool->size(); i++) {
        (*pool)[i]->update(game);
    }
}

void UpdatePool::clear() {
    pool->clear();
}
