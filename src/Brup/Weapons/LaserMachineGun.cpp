#include "LaserMachineGun.h"
#include "Projectiles/ShortRedLaser.h"

brup::weapons::projectiles::Projectile *brup::weapons::LaserMachineGun::getNewProjectile()
{
    return new brup::weapons::projectiles::ShortRedLaser();
}
