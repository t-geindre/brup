#include "Projectile.h"
#include "../../../Engine/Game.h"

void brup::weapons::projectiles::Projectile::update(engine::Game *game) {
    xPosition += xVelocity * game->getElapsedTime();
    yPosition += yVelocity * game->getElapsedTime();

    if (yPosition < 0 || yPosition > game->getRenderTarget()->getView().getSize().y) {
        destroy(game);
    }
}

void brup::weapons::projectiles::Projectile::setPosition(float x, float y) {
    xPosition = x;
    yPosition = y;
}
