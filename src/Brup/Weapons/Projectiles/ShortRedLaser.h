#ifndef GAME_SHORTREDLASER_H
#define GAME_SHORTREDLASER_H

#include "Projectile.h"
#include <SFML/Graphics/RenderTarget.hpp>

namespace brup::weapons::projectiles {
    class ShortRedLaser : public Projectile
    {
        public:
            ShortRedLaser();
            void draw(sf::RenderTarget *target);

        void update(engine::Game *game) override;
    };
}

#endif //GAME_SHORTREDLASER_H
