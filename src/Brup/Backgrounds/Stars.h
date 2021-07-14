#ifndef GAME_STARS_H
#define GAME_STARS_H

#include "../../Engine/Updatable.h"
#include "../../Engine/Drawable.h"
#include "../../Engine/Initable.h"
#include "../../Engine/Game.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

namespace brup::backgrounds {
    struct Star {
        float posX;
        float posY;
        int depth;
        int brightness;
    };

    class Stars : public engine::Updatable, public engine::Drawable, public engine::Initable {
        public:
            void init(engine::Game *game);
            void draw(sf::RenderTarget *target);
            void update(engine::Game *game);
        private:
            void resetStar(int star, engine::Game *game, bool top = false);
            Star stars[200];
            const int starsCount = 200;
    };
}

#endif //GAME_STARS_H
