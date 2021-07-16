#ifndef GAME_PLAYING_H
#define GAME_PLAYING_H

#include "../../Engine/GameObject.h"
#include "../Player/Ship.h"

namespace brup::scenes {
    class Playing : public engine::GameObject {
        public:
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            void draw(sf::RenderTarget *target) override;
            unsigned int getDrawPriority() override;
        private:
            int spawnRate = 100;
            int lastSpawnElapsedTime = 0;
            float starting = 100;
    };
}

#endif //GAME_PLAYING_H
