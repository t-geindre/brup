#ifndef GAME_UPDATABLE_H
#define GAME_UPDATABLE_H

#include <SFML/Graphics/RenderTarget.hpp>

namespace engine {
    class Game;
    class Updatable {
        public:
            virtual void update(Game *game) = 0;
    };
}

#endif //GAME_UPDATABLE_H
