#ifndef GAME_FRAMEPERSECOND_H
#define GAME_FRAMEPERSECOND_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../GameObject.h"

namespace engine {
    class FramePerSecond : public GameObject {
        public:
            void draw(sf::RenderTarget *target) override;
            void update(Game *game) override;
            unsigned int getDrawPriority() override;
            void init(Game *game) override;

        private:
            int fps = 0;
            float lastTime = 0;
            sf::Font font;
            sf::Text display;
    };
}

#endif //GAME_FRAMEPERSECOND_H
