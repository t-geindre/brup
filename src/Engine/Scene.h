#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Updatable.h"

namespace engine {
    class Game;
    class Scene : public Updatable {
        public:
            virtual void reset(Game *game) = 0;
    };
}

#endif //GAME_SCENE_H
