#ifndef GAME_UPDATEPOOL_H
#define GAME_UPDATEPOOL_H

#include <vector>
#include "Updatable.h"

namespace engine {
    class Game;
    class UpdatePool : public Updatable {
        public:
            UpdatePool();
            void push(Updatable *updatable);
            void remove(Updatable *updatable);
            void update(Game *game);
            void clear();
        private:
            std::vector<Updatable*>* pool;
    };
}

#endif //GAME_UPDATEPOOL_H
