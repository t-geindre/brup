#include "Enemy.h"
#include "../Weapons/Projectiles/Projectile.h"
#include "../Events/EnemyKilled.h"

using namespace brup::enemies;
using namespace brup::weapons::projectiles;
using namespace brup::events;

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
    game->getEventDispatcher()->dispatch(new EnemyKilled);
    animateDestruction(game);
    destroy(game);
}
