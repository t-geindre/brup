#include "Weapon.h"
#include "../../Engine/Game.h"

using namespace brup::weapons;
using namespace brup::weapons::projectiles;

void Weapon::setIsFiring(bool isFiring) {
    this->isFiring = isFiring;
}

void Weapon::update(engine::Game *game) {
    if (lastShootElapsedTime < fireRate) {
        lastShootElapsedTime += game->getElapsedTime();
        return;
    }

    if (!isFiring) {
        return;
    }

    Projectile *projectile = getNewProjectile();
    projectile->setPosition(posX, posY);
    game->addObject(projectile);

    lastShootElapsedTime = 0;
}

void Weapon::setPosition(float x, float y) {

    posX = x;
    posY = y;
}
