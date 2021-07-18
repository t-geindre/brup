#include "Enemy.h"
#include "../Weapons/Projectiles/Projectile.h"

using namespace brup::enemies;
using namespace brup::weapons::projectiles;

void Enemy::init(engine::Game *game) {
    game->getCollisionPool()->push(this);
    engine::GameObject::init(game);
}

void Enemy::collisionWith(engine::Collidable *collidable, engine::Game *game) {
    if(auto* projectile = dynamic_cast<Projectile*>(collidable)) {
        kill(game);
        projectile->destroy(game);
    }
}

void Enemy::destroy(engine::Game *game) {
    game->getCollisionPool()->remove(this);
    GameObject::destroy(game);
}

void Enemy::kill(engine::Game *game) {
    animateDestruction(game);
    destroy(game);
}
