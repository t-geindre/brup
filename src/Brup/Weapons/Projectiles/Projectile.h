#ifndef GAME_PROJECTILE_H
#define GAME_PROJECTILE_H

#include "../../../Engine/GameObject.h"
#include "../../../Engine/Collision/Collidable.h"
#include <SFML/Graphics/RenderTarget.hpp>

namespace brup::weapons::projectiles {
    class Projectile : public engine::GameObject, public engine::Collidable {
        public:
            void update(engine::Game *game) override;
            void init(engine::Game *game) override;
            void destroy(engine::Game *game) override;
            int getDamages();
            void setIsEnemy(bool isEnemy);
            bool getIsEnemy();

        protected:
            float xVelocity = 0;
            float yVelocity = 0;
            int damages = 1;
            bool isEnemy = false;
    };
}

#endif //GAME_PROJECTILE_H
