#include "Projectile.h"
#include "../../../Engine/Game.h"

void brup::weapons::projectiles::Projectile::update(engine::Game *game) {
    xPosition += xVelocity * game->getElapsedTime();
    yPosition += yVelocity * game->getElapsedTime();

    if (yPosition < 0 || yPosition > game->getRenderTarget()->getView().getSize().y) {
        game->getUpdatePool()->remove(this);
        game->getDrawPool()->remove(this);
        delete this;
    }
}

void brup::weapons::projectiles::Projectile::setPosition(float x, float y) {
    xPosition = x;
    yPosition = y;
}

void brup::weapons::projectiles::Projectile::init(engine::Game *game) {
    game->getDrawPool()->push(this);
    game->getUpdatePool()->push(this);
}
