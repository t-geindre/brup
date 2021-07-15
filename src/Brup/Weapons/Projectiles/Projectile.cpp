#include "Projectile.h"


using namespace brup::weapons::projectiles;

void Projectile::update(engine::Game *game) {
    xPosition += xVelocity * game->getElapsedTime();
    yPosition += yVelocity * game->getElapsedTime();

    if (yPosition < 0 || yPosition > game->getRenderTarget()->getView().getSize().y) {
        destroy(game);
    }
}

void Projectile::setPosition(float x, float y) {
    xPosition = x;
    yPosition = y;
}

void Projectile::init(engine::Game *game) {
    game->getCollisionPool()->push(this);
    GameObject::init(game);
}

void Projectile::destroy(engine::Game *game) {
    game->getCollisionPool()->remove(this);
    GameObject::destroy(game);
}

int Projectile::getDamages() {
    return damages;
}

void Projectile::setIsEnemy(bool isEnemy) {
    this->isEnemy = isEnemy;
}

bool Projectile::getIsEnemy() {
    return isEnemy;
}
