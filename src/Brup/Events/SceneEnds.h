#ifndef GAME_SCENEENDS_H
#define GAME_SCENEENDS_H

#include "../../Engine/Event/Event.h"

namespace brup::events {
    class SceneEnds : public engine::Event {
        public:
            static const std::string NAME;
            std::string getName();
    };
}

#endif //GAME_SCENEENDS_H
