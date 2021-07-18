#ifndef GAME_COLLISIONMASKS_H
#define GAME_COLLISIONMASKS_H

#include "../GameObject.h"
#include "../Collision/CollisionPool.h"

namespace engine {
    class CollisionMasks : public GameObject {
        public:
            void init(Game *game) override;
            void draw(sf::RenderTarget *target) override;
            unsigned int getDrawPriority() override;
        private:
            CollisionPool *pool;
    };
}

#endif //GAME_COLLISIONMASKS_H
