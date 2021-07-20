#ifndef GAME_EVENTDISPATCHER_H
#define GAME_EVENTDISPATCHER_H

#include <unordered_map>
#include <functional>
#include <vector>
#include "Event.h"

namespace engine {
    class EventDispatcher {
        public:
            void addListener(std::string event, std::function<void(Event* event)> listener);
            void dispatch(Event *event);
        private:
            std::unordered_map<std::string, std::vector<std::function<void(Event*)>>*> listeners;
    };
}

#endif //GAME_EVENTDISPATCHER_H
