#ifndef GAME_COLLIDABLE_H
#define GAME_COLLIDABLE_H

#include "../Game.h"

namespace engine {
    struct CollisionMask {
        float x;
        float y;
        float width;
        float height;
    };

    class Collidable {
        public:
            virtual CollisionMask getCollisionMask() = 0;
            virtual void collisionWith(Collidable *collidable, Game *game);
    };
}

#endif //GAME_COLLIDABLE_H
