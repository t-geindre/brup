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
    posX = rand() % ((int) game->getRenderTarget()->getSize().x - 200) + 100;
    posY = -30;

    int l = rand() % 3;
    shipColor.r = l == 0 ? 255 : 0; 229;
    shipColor.g = l == 1 ? 255 : 0; //9;
    shipColor.b = l == 2 ? 255 : 0; //20;

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
    posX += sin(posY/80) * 0.2 * game->getElapsedTime();

    ship.setPosition(posX, posY);

    if (posY > game->getRenderTarget()->getView().getSize().y + 30) {
        destroy(game);
    }
}

engine::CollisionMask Netflix::getCollisionMask() {
    return engine::CollisionMask {
        posX - 20,
        posY - 30,
        40,
        60
    };
}

void Netflix::animateDestruction(engine::Game *game) {
        auto* explosion = new ParticleExplosion;
        explosion->setPosition(posX, posY);
        explosion->pushParticlesColor(shipColor);
        explosion->setParticlesSize(2, 4);
        explosion->setParticlesVelocity(.05, .5);
        explosion->setParticlesCount(100);
        explosion->setParticlesFadeSpeed(.05, .08);
        game->addObject(explosion);
}
