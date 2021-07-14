#ifndef GAME_STARS_H
#define GAME_STARS_H

#include "../../Engine/Update/Updatable.h"
#include "../../Engine/Draw/Drawable.h"
#include "../../Engine/Initable.h"
#include "../../Engine/Game.h"
#include "../../Engine/GameObject.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

namespace brup::backgrounds {
    struct Star {
        float posX;
        float posY;
        int depth;
        int brightness;
    };

    class Stars : public engine::GameObject {
        public:
        void init(engine::Game *game) override;

        void draw(sf::RenderTarget *target) override;
            void update(engine::Game *game) override;
        private:
            void resetStar(int star, engine::Game *game, bool top = false);
            Star stars[200];
            const int starsCount = 200;
    };
}

#endif //GAME_STARS_H
