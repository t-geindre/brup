#ifndef GAME_INITABLE_H
#define GAME_INITABLE_H

namespace engine {
    class Game;
    class Initable {
        public:
            virtual void init(Game *game) = 0;
    };
}

#endif //GAME_INITABLE_H
