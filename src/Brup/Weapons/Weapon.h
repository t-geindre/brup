#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "Projectiles/Projectile.h"
#include "../../Engine/Updatable.h"
#include "../../Engine/Initable.h"

namespace brup::weapons {
class Weapon : public engine::Updatable , public engine::Initable {
        public:
            void setIsFiring(bool isFiring);
            void setPosition(float x, float y);
            void update(engine::Game *game);
            void init(engine::Game *game) override;
        protected:
            virtual brup::weapons::projectiles::Projectile* getNewProjectile() = 0;
            // fire rate, one shoot each X ms
            int fireRate = 100;
            bool isFiring = false;
            int lastShootElapsedTime = 0;
            float posX, posY;
    };
}

#endif //GAME_WEAPON_H
