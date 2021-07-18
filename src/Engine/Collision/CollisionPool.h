#ifndef GAME_COLLISIONPOOL_H
#define GAME_COLLISIONPOOL_H

#include <vector>
#include "../Update/Updatable.h"

namespace engine {
    class Collidable;
    class CollisionPool : public Updatable {
        public:
            CollisionPool();
            void update(Game *game) override;
            void push(Collidable *collidable);
            void remove(Collidable *collidable);
            void clear();
            std::vector<Collidable*>* getVector();
        private:
            std::vector<Collidable*>* pool;
    };
}

#endif //GAME_COLLISIONPOOL_H
