#ifndef GAME_NETFLIX_H
#define GAME_NETFLIX_H

#include "../../Engine/Drawable.h"
#include "../../Engine/Updatable.h"
#include "../../Engine/Initable.h"

namespace brup::enemies {
    class Netflix : public engine::Drawable, public engine::Updatable, public engine::Initable  {
        public:
            void draw(sf::RenderTarget *target) override;
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
        private:
            float posX, posY;
    };
}


#endif //GAME_NETFLIX_H
