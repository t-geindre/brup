#ifndef GAME_NETFLIX_H
#define GAME_NETFLIX_H

#include "Enemy.h"

namespace brup::enemies {
    class Netflix : public Enemy  {
        public:
            void draw(sf::RenderTarget *target) override;
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            engine::CollisionMask getCollisionMask() override;
            void animateDestruction(engine::Game *game) override;
    private:
            float posX, posY;
            sf::ConvexShape ship;
            sf::Color shipColor;
    };
}

#endif //GAME_NETFLIX_H
