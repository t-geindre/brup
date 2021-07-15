#include <SFML/Graphics/ConvexShape.hpp>
#include <iostream>
#include "Netflix.h"
#include "../../Engine/Game.h"
#include "math.h"
#include "../Weapons/Projectiles/Projectile.h"

using namespace brup::enemies;
using namespace brup::weapons::projectiles;

void Netflix::draw(sf::RenderTarget *target) {
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

    sf::ConvexShape ship;
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

    ship.setPosition(posX, posY);
    ship.setFillColor(sf::Color(229, 9, 20));

    target->draw(ship);
}

void Netflix::init(engine::Game *game) {
    engine::GameObject::init(game);

    game->getCollisionPool()->push(this);

    posX = rand() % ((int) game->getRenderTarget()->getSize().x + 200) - 100;
    posY = -30;
}

void Netflix::update(engine::Game *game) {
    posY += .2 * game->getElapsedTime();
    posX = posX + sin(posY/80);

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
        projectile->destroy(game);
        destroy(game);
    }
}
