#ifndef GAME_LASERMACHINEGUN_H
#define GAME_LASERMACHINEGUN_H

#include "Weapon.h"
#include "Projectiles/Projectile.h"

namespace brup::weapons {
    class LaserMachineGun : public Weapon {
        public:
            brup::weapons::projectiles::Projectile* getNewProjectile();
    };
}

#endif //GAME_LASERMACHINEGUN_H
