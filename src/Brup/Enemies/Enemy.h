#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "../../Engine/GameObject.h"
#include "../../Engine/Collision/Collidable.h"

namespace brup::enemies {
    class Enemy : public engine::GameObject, public engine::Collidable  {
        public:
            void init(engine::Game *game) override;

        void destroy(engine::Game *game) override;

        void collisionWith(engine::Collidable *collidable, engine::Game *game) override;
            virtual void animateDestruction(engine::Game *game) = 0;
        private:
            float posX, posY;
    };
}

#endif //GAME_ENEMY_H
