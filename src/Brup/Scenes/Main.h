#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include "../../Engine/GameObject.h"
#include "../Player/Ship.h"

namespace brup::scenes {
    class Main : public engine::GameObject {
        public:
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            void draw(sf::RenderTarget *target) override;

        private:
            int spawnRate = 100;
            int lastSpawnElapsedTime = 0;
            float starting = 100;
    };
}

#endif //GAME_MAIN_H
