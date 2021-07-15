#ifndef GAME_BRUP_H
#define GAME_BRUP_H

#include "../Engine/Game.h"
#include "../Engine/GameObject.h"

namespace brup {
    class Game : public engine::Game{
        public:
            Game();

        protected:
            engine::GameObject *scene;
    };
}

#endif //GAME_GAME_H
