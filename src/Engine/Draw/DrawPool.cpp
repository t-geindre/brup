#include <iostream>
#include "DrawPool.h"

using namespace engine;

DrawPool::DrawPool() {
    pool = new std::vector<Drawable*>;
}

void DrawPool::draw(sf::RenderTarget *target) {
    for (int i = 0; i < pool->size(); i++) {
        (*pool)[i]->draw(target);
    }
}

void DrawPool::push(Drawable *drawable) {
    pool->push_back(drawable);
    std::sort(pool->begin(), pool->end(), [](Drawable *a, Drawable *b) {
        return a->getDrawPriority() < b->getDrawPriority();
    });
}

bool DrawPool::remove(Drawable *drawable) {
    for (int i = 0; i < pool->size(); i++) {
        if ((*pool)[i] == drawable) {
            pool->erase(pool->begin()+i);
            return true;
        }
    }

    return false;
}

void DrawPool::clear() {
    pool->clear();
}

unsigned int DrawPool::getDrawPriority() {
    return 0;
}

void DrawPool::toggle(Drawable *drawable) {
    if (!this->remove(drawable)) {
        this->push(drawable);
    }
}

