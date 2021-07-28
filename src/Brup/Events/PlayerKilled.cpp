#include "PlayerKilled.h"

using namespace brup::events;

std::string PlayerKilled::getName() {
    return PlayerKilled::NAME;
}

const std::string PlayerKilled::NAME = "PLAYER_KILLED";

