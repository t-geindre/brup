#ifndef GAME_STAGETITLE_H
#define GAME_STAGETITLE_H

#include "../../Engine/GameObject.h"

namespace brup::scenes {
    class StageTitle : public engine::GameObject {
        public:
            void init(engine::Game *game) override;
            void draw(sf::RenderTarget *target) override;
            void update(engine::Game *game) override;

        private:
            sf::Font font;
            sf::Text title;
            sf::RectangleShape background;
            float displayTime = 2100; // ms
            float titleDisplayTime = 2000;
            float titleFade = 100;
    };
}

#endif //GAME_STAGETITLE_H
