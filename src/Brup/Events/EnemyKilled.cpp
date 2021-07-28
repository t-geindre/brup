#include "EnemyKilled.h"

using namespace brup::events;

std::string EnemyKilled::getName() {
    return EnemyKilled::NAME;
}

const std::string EnemyKilled::NAME = "ENEMY_KILLED";

