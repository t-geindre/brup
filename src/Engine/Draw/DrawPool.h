#ifndef GAME_DRAWPOOL_H
#define GAME_DRAWPOOL_H

#include <vector>
#include "Drawable.h"

namespace engine {
    class DrawPool : public Drawable {
        public:
            DrawPool();
            void push(Drawable *drawable);
            void remove(Drawable *drawable);
            void draw(sf::RenderTarget *target);
            void clear();
        private:
            std::vector<Drawable*>* pool;
    };
}

#endif //GAME_DRAWPOOL_H
