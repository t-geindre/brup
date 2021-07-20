#include "EventDispatcher.h"


using namespace engine;

void EventDispatcher::addListener(std::string event, std::function<void(Event* event)> listener) {
    if (listeners.find(event) == listeners.end()) {
        listeners[event] = new std::vector<std::function<void(Event*)>>;
    }

    listeners[event]->push_back(listener);
}

void EventDispatcher::dispatch(Event *event) {
    std::string name = event->getName();

    if (listeners.find(name) == listeners.end()) {
        return;
    }

    auto* pool = listeners[name];
    for (int i = 0; i < pool->size(); i++) {
        (*pool)[i](event);
    }
}
