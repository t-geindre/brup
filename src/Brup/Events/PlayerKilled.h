#ifndef GAME_PLAYERKILLED_H
#define GAME_PLAYERKILLED_H

#include "../../Engine/Event/Event.h"

namespace brup::events {
    class PlayerKilled : public engine::Event {
        public:
            static const std::string NAME;
            std::string getName();
    };
}

#endif //GAME_PLAYERKILLED_H
