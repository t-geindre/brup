#ifndef GAME_DRAWABLE_H
#define GAME_DRAWABLE_H

#include <SFML/Graphics/RenderTarget.hpp>

namespace engine {
    class Drawable {
        public:
            virtual void draw(sf::RenderTarget *target) = 0;
    };
}

#endif //GAME_DRAWABLE_H
