#ifndef GAME_STAGETITLE_H
#define GAME_STAGETITLE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
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
            float displayTime = 2500; // ms
            float titleDisplayTime = 2000;
            float titleFade = 100;
    };
}

#endif //GAME_STAGETITLE_H
