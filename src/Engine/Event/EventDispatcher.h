#ifndef GAME_EVENTDISPATCHER_H
#define GAME_EVENTDISPATCHER_H

#include <unordered_map>
#include <functional>
#include <vector>
#include "Event.h"

namespace engine {
    struct Listener {
        std::string eventName;
        std::function<void(Event* event)> callable;
        uint id;
    };
    class EventDispatcher {
        public:
            uint addListener(std::string event, std::function<void(Event* event)> callable);
            void removeListener(uint id);
            void dispatch(Event *event);
        private:
            uint id = 0;
            std::vector<Listener*> listeners;
    };
}

#endif //GAME_EVENTDISPATCHER_H
