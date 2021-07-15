#ifndef GAME_COLLIDABLE_H
#define GAME_COLLIDABLE_H

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
            void CollisionWith(Collidable *collidable);
    };
}

#endif //GAME_COLLIDABLE_H
