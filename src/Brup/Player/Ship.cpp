#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Ship.h"
#include "../Enemies/Enemy.h"
#include "../Effects/ParticleExplosion.h"
#include "../Events/PlayerKilled.h"
#include "../Events/SceneEnds.h"

using namespace brup::player;
using namespace brup::weapons;
using namespace brup::enemies;
using namespace brup::effects;
using namespace brup::events;

void Ship::draw(sf::RenderTarget *target) {
    target->draw(ship);
}

void Ship::setMovements(int x, int y) {
    move.x = x;
    move.y = y;
}

void Ship::update(engine::Game *game) {
    if (invincible > 0) {
        invincible -= game->getElapsedTime();
        shipColor.a = invincible > 0 && invincible % 200 > 150 ? 0 : 255;
        ship.setFillColor(shipColor);
    }

    setMovements(
          sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ? -1 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ? 1 : 0),
          sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? -1 : (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ? 1 : 0)
    );

    position.x += .8 * move.x * game->getElapsedTime();
    position.y += .8 * move.y * game->getElapsedTime();

    float posYMax = game->getRenderTarget()->getView().getSize().y;
    float poxXMax = game->getRenderTarget()->getView().getSize().x;

    position.y = position.y < 0 ? 0 : ( position.y > posYMax ? posYMax : position.y);
    position.x = position.x < 0 ? 0 : ( position.x > poxXMax ? poxXMax : position.x);

    ship.setPosition(position);

    if (weapon == NULL) {
        return;
    }

    weapon->setPosition(position);
    weapon->setIsFiring(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
}

void Ship::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void Ship::init(engine::Game *game) {
    listeners.push_back(game->getEventDispatcher()->addListener(SceneEnds::NAME, [&](engine::Event *event) {
        // destroy(game);
    }));

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

    setPosition(
        game->getRenderTarget()->getView().getCenter().x,
        game->getRenderTarget()->getView().getSize().y - 40.f
    );

    setMovements(0, 0);

    game->getCollisionPool()->push(this);

    engine::GameObject::init(game);
}

engine::CollisionMask Ship::getCollisionMask() {
    return engine::CollisionMask {
        position.x - 22,
        position.y - 35,
        44,
        55
    };
}

void Ship::collisionWith(engine::Collidable *collidable, engine::Game *game) {
    if (invincible > 0) {
        return;
    }

    if(auto* enemy = dynamic_cast<Enemy*>(collidable)) {
        weapon->setIsFiring(false);
        game->getEventDispatcher()->dispatch(new PlayerKilled);
        animateDestruction(game);
        enemy->kill(game);
        destroy(game);
    }
}

void Ship::destroy(engine::Game *game) {
    game->getCollisionPool()->remove(this);
    GameObject::destroy(game);
}

void Ship::animateDestruction(engine::Game *game) {
    auto* explosion = new ParticleExplosion;
    explosion->setPosition(position);
    explosion->pushParticlesColor(shipColor);
    explosion->setParticlesSize(2, 4);
    explosion->setParticlesVelocity(.05, .5);
    explosion->setParticlesCount(200);
    explosion->setParticlesFadeSpeed(.05, .08);
    game->addObject(explosion);
}
