#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include <string>

namespace engine {
    class Event {
        public:
            static const std::string NAME;
            virtual std::string getName();
    };
}

#endif //GAME_EVENT_H
