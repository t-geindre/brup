#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "Updatable.h"
#include "Drawable.h"
#include "Initable.h"
#include "Game.h"

namespace engine {
    class GameObject: public Updatable, public Drawable, public Initable {
        public:
            void init(Game *game) override;
            void draw(sf::RenderTarget *target) override;
            void update(Game *game) override;
            void destroy(Game *game);
    };
}


#endif //GAME_GAMEOBJECT_H
