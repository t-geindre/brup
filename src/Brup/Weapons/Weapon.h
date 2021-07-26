#ifndef GAME_WEAPON_H
#define GAME_WEAPON_H

#include "Projectiles/Projectile.h"
#include "../../Engine/GameObject.h"

namespace brup::weapons {
class Weapon : public engine::GameObject {
        public:
            void setIsFiring(bool isFiring);
            void update(engine::Game *game) override;
        protected:
            virtual brup::weapons::projectiles::Projectile* getNewProjectile() = 0;
            // fire rate, one shoot each X ms
            int fireRate = 50;
            bool isFiring = false;
            int lastShootElapsedTime = 0;
    };
}

#endif //GAME_WEAPON_H
