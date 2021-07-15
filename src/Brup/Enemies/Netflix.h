#ifndef GAME_NETFLIX_H
#define GAME_NETFLIX_H

#include "../../Engine/GameObject.h"
#include "../../Engine/Collision/Collidable.h"

namespace brup::enemies {
    class Netflix : public engine::GameObject, public engine::Collidable  {
        public:
            void draw(sf::RenderTarget *target) override;
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            void destroy(engine::Game *game) override;
            engine::CollisionMask getCollisionMask() override;
            void collisionWith(engine::Collidable *collidable, engine::Game *game) override;
        private:
            float posX, posY;
            bool isDying = false;
            float dyingProcess = 100;
            sf::ConvexShape shipLeft;
            sf::ConvexShape shipRight;
    };
}


#endif //GAME_NETFLIX_H
