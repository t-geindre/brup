#include "EventDispatcher.h"


using namespace engine;

uint EventDispatcher::addListener(std::string event, std::function<void(Event* event)> callable) {
    uint listenerId = ++id;
    listeners.push_back(new Listener{event, callable, listenerId});

    return listenerId;
}

void EventDispatcher::dispatch(Event *event) {
    for (int i = 0; i < listeners.size(); i++) {
        if (listeners[i]->eventName == event->getName()) {
            listeners[i]->callable(event);
        }
    }
}

void EventDispatcher::removeListener(uint id) {
    for (int i = 0; i < listeners.size(); i++) {
        if (listeners[i]->id == id) {
            listeners.erase(listeners.begin()+i);
        }
    }
}
