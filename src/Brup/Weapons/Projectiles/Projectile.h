#ifndef GAME_PROJECTILE_H
#define GAME_PROJECTILE_H

#include "../../../Engine/GameObject.h"
#include <SFML/Graphics/RenderTarget.hpp>

namespace brup::weapons::projectiles {
    class Projectile : public engine::GameObject {
        public:
            void setPosition(float x, float y);
            void update(engine::Game *game) override;
        protected:
            float xVelocity = 0;
            float yVelocity = 0;
            float xPosition = 0;
            float yPosition = 0;
    };
}

#endif //GAME_PROJECTILE_H
