#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include "../../Engine/Scene.h"
#include "../Player/Ship.h"

namespace brup::scenes {
    class Main : public engine::Scene {
        public:
            void init(engine::Game *game);
            void update(engine::Game *game) override;
        private:
            int spawnRate = 300;
            int lastSpawnElapsedTime = 0;
    };
}


#endif //GAME_MAIN_H
