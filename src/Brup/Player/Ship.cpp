#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Ship.h"
#include "../Enemies/Enemy.h"
#include "../Effects/ParticleExplosion.h"

using namespace brup::player;
using namespace brup::weapons;
using namespace brup::enemies;
using namespace brup::effects;

void Ship::draw(sf::RenderTarget *target) {
    if (dead) {
        return;
    }

    target->draw(ship);
}

void Ship::setMovements(int x, int y) {
    xMove = x;
    yMove = y;
}

void Ship::update(engine::Game *game) {
    if (dead) {
        deathRecovery -= game->getElapsedTime();
        if (deathRecovery > 0) {
            return;
        }
        dead = false;
        invincible = 3000;
    }

    if (invincible > 0) {
        invincible -= game->getElapsedTime();
    }

    setMovements(
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ? -1 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ? 1 : 0),
            sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? -1 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ? 1 : 0)
            );

    posX += .8 * xMove * game->getElapsedTime();
    posY += .8 * yMove * game->getElapsedTime();

    float posYMax = game->getRenderTarget()->getView().getSize().y;
    float poxXMax = game->getRenderTarget()->getView().getSize().x;

    posY = posY < 0 ? 0 : ( posY > posYMax ? posYMax : posY);
    posX = posX < 0 ? 0 : ( posX > poxXMax ? poxXMax : posX);

    ship.setPosition(posX, posY);

    if (weapon == NULL) {
        return;
    }

    weapon->setPosition(posX, posY);
    weapon->setIsFiring(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
}

void Ship::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void Ship::init(engine::Game *game) {
    shipColor.r = 251;
    shipColor.g = 87;
    shipColor.b = 66;

    sf::Vector2f topSpike(0, -35);
    sf::Vector2f leftCavity(-10, 0);
    sf::Vector2f rightCavity(10, 0);
    sf::Vector2f leftSpike(-22, 20);
    sf::Vector2f rightSpike(22, 20);
    sf::Vector2f bottomCavity(0, 10);

    ship.setPointCount(6);
    ship.setPoint(0, topSpike);
    ship.setPoint(1, leftCavity);
    ship.setPoint(2, leftSpike);
    ship.setPoint(3, bottomCavity);
    ship.setPoint(4, rightSpike);
    ship.setPoint(5, rightCavity);
    ship.setPoint(6, topSpike);

    ship.setFillColor(shipColor);

    resetPosition(game);

    xMove = 0;
    yMove = 0;

    game->getCollisionPool()->push(this);

    engine::GameObject::init(game);
}

engine::CollisionMask Ship::getCollisionMask() {
    return engine::CollisionMask {
        posX - 22,
        posY - 35,
        44,
        55
    };
}

void Ship::collisionWith(engine::Collidable *collidable, engine::Game *game) {
    if (dead || invincible > 0) {
        return;
    }

    if(auto* enemy = dynamic_cast<Enemy*>(collidable)) {
        dead = true;
        deathRecovery = 5000;
        weapon->setIsFiring(false);
        animateDestruction(game);
        enemy->kill(game);
        resetPosition(game);
    }
}

void Ship::destroy(engine::Game *game) {
    game->getCollisionPool()->remove(this);
    GameObject::destroy(game);
}

void Ship::animateDestruction(engine::Game *game) {
    auto* explosion = new ParticleExplosion;
    explosion->setPosition(posX, posY);
    explosion->pushParticlesColor(shipColor);
    explosion->setParticlesSize(2, 4);
    explosion->setParticlesVelocity(.05, .5);
    explosion->setParticlesCount(200);
    explosion->setParticlesFadeSpeed(.05, .08);
    game->addObject(explosion);
}

void Ship::resetPosition(engine::Game *game) {
    posX = game->getRenderTarget()->getView().getCenter().x;
    posY = game->getRenderTarget()->getView().getSize().y - 40.f;
}
