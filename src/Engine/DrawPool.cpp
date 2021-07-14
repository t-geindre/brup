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
}

void DrawPool::remove(Drawable *drawable) {
    for (int i = 0; i < pool->size(); i++) {
        if ((*pool)[i] == drawable) {
            pool->erase(pool->begin()+i);
            return;
        }
    }
}

void DrawPool::clear() {
    pool->clear();
}

