#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include "../../Engine/GameObject.h"
#include "../Player/Ship.h"

namespace brup::scenes {
    class Main : public engine::GameObject {
        public:
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
        private:
            int spawnRate = 200;
            int lastSpawnElapsedTime = 0;
    };
}

#endif //GAME_MAIN_H
