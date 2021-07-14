#ifndef GAME_NETFLIX_H
#define GAME_NETFLIX_H

#include "../../Engine/GameObject.h"

namespace brup::enemies {
    class Netflix : public engine::GameObject  {
        public:
            void draw(sf::RenderTarget *target) override;
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
        private:
            float posX, posY;
    };
}


#endif //GAME_NETFLIX_H
