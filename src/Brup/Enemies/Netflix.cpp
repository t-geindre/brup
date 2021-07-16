#include "Netflix.h"
#include "math.h"
#include "../Weapons/Projectiles/Projectile.h"
#include "../Effects/ParticleExplosion.h"

using namespace brup::enemies;
using namespace brup::weapons::projectiles;
using namespace brup::effects;

void Netflix::draw(sf::RenderTarget *target) {
    target->draw(ship);
}

void Netflix::init(engine::Game *game) {
    posX = rand() % ((int) game->getRenderTarget()->getSize().x + 200) - 100;
    posY = -30;

    shipColor.r = rand() % 256; //229;
    shipColor.g = rand() % 256; //9;
    shipColor.b = rand() % 256; //20;

    sf::Vector2f tll(-20, -30);
    sf::Vector2f tlr(-8, -30);
    sf::Vector2f tc(0, -5);
    sf::Vector2f trl(8, -30);
    sf::Vector2f trr(20, -30);
    sf::Vector2f brr(20, 30);
    sf::Vector2f brl(8, 30);
    sf::Vector2f bc(0, 5);
    sf::Vector2f blr(-8, 30);
    sf::Vector2f bll(-20, 30);

    ship.setPointCount(10);
    ship.setPoint(0, tll);
    ship.setPoint(1, tlr);
    ship.setPoint(2, tc);
    ship.setPoint(3, trl);
    ship.setPoint(4, trr);
    ship.setPoint(5, brr);
    ship.setPoint(6, brl);
    ship.setPoint(7, bc);
    ship.setPoint(8, blr);
    ship.setPoint(9, bll);

    ship.setFillColor(shipColor);

    game->getCollisionPool()->push(this);

    engine::GameObject::init(game);
}

void Netflix::update(engine::Game *game) {
    posY += .2 * game->getElapsedTime();
    posX = posX + sin(posY/80);

    ship.setPosition(posX, posY);

    if (posY > game->getRenderTarget()->getView().getSize().y + 30) {
        destroy(game);
    }
}

void Netflix::destroy(engine::Game *game) {
    game->getCollisionPool()->remove(this);
    GameObject::destroy(game);
}

engine::CollisionMask Netflix::getCollisionMask() {
    return engine::CollisionMask {
        posX - 20,
        posY - 30,
        40,
        60
    };
}

void Netflix::collisionWith(engine::Collidable *collidable, engine::Game *game) {
    if(auto* projectile = dynamic_cast<Projectile*>(collidable)) {
        auto* explosion = new ParticleExplosion;
        explosion->setPosition(posX, posY);
        explosion->pushParticlesColor(shipColor);
        explosion->setParticlesSize(3, 6);
        explosion->setParticlesCount(50);
        explosion->setParticlesVelocity(.005, .5);
        game->addObject(explosion);

        destroy(game);
        projectile->destroy(game);
    }
}
