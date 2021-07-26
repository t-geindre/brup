#include "Projectile.h"


using namespace brup::weapons::projectiles;

void Projectile::update(engine::Game *game) {
    position.x += xVelocity * game->getElapsedTime();
    position.y += yVelocity * game->getElapsedTime();

    if (position.y < 0 || position.y > game->getRenderTarget()->getView().getSize().y) {
        destroy(game);
    }
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
