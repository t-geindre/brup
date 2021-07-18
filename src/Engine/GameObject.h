#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "Update/Updatable.h"
#include "Draw/Drawable.h"
#include "Initable.h"

namespace engine {
    class Game;
    class GameObject: public Updatable, public Drawable, public Initable {
        public:
            void init(Game *game) override;
            void draw(sf::RenderTarget *target) override;
            unsigned int getDrawPriority() override;
            void update(Game *game) override;
            virtual void destroy(Game *game);
    };
}


#endif //GAME_GAMEOBJECT_H
