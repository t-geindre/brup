#ifndef GAME_BRUP_H
#define GAME_BRUP_H

#include "../Engine/Game.h"
#include "../Engine/GameObject.h"

namespace brup {
    class Game : public engine::Game{
        public:
            Game();
            void nextState();
        protected:
            enum STATES:int {
                NONE,
                STAGE_TITLE,
                PLAYING
            };
            engine::GameObject *scene;
            int state;
    };
}

#endif //GAME_GAME_H
