#ifndef GAME_ENEMYKILLED_H
#define GAME_ENEMYKILLED_H

#include "../../Engine/Event/Event.h"

namespace brup::events {
    class EnemyKilled : public engine::Event {
        public:
            static const std::string NAME;
            std::string getName();
    };
}

#endif //GAME_ENEMYKILLED_H
