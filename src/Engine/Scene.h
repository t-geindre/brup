#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Updatable.h"
#include "Initable.h"

namespace engine {
    class Scene : public Updatable, public Initable {
    };
}

#endif //GAME_SCENE_H
