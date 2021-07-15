#ifndef GAME_COLLISIONPOOL_H
#define GAME_COLLISIONPOOL_H

#include <vector>
#include "../Update/Updatable.h"
#include "Collidable.h"

namespace engine {
    class CollisionPool : public Updatable {
        public:
            CollisionPool();
            void update(Game *game) override;
            void push(Collidable *collidable);
            void remove(Collidable *collidable);
            void clear();
        private:
            std::vector<Collidable*>* pool;
    };
}

#endif //GAME_COLLISIONPOOL_H
