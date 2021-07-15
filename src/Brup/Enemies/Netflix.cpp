#include <SFML/Graphics/ConvexShape.hpp>
#include "Netflix.h"
#include "math.h"
#include "../Weapons/Projectiles/Projectile.h"

using namespace brup::enemies;
using namespace brup::weapons::projectiles;

void Netflix::draw(sf::RenderTarget *target) {
    sf::Color shipColor(229, 9, 20, !isDying ? 255 : (int) (dyingProcess * 2.55));

    shipLeft.setPosition(posX - (isDying ? 30 - dyingProcess * 0.3 : 0 ), posY);
    shipLeft.setFillColor(shipColor);
    target->draw(shipLeft);

    shipRight.setPosition(posX + (isDying ? 30 - dyingProcess * 0.3 : 0 ), posY);
    shipRight.setFillColor(shipColor);
    target->draw(shipRight);
}

void Netflix::init(engine::Game *game) {
    posX = rand() % ((int) game->getRenderTarget()->getSize().x + 200) - 100;
    posY = -30;

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

    shipLeft.setPointCount(7);
    shipLeft.setPoint(0, tll);
    shipLeft.setPoint(1, tlr);
    shipLeft.setPoint(2, tc);
    shipLeft.setPoint(3, bc);
    shipLeft.setPoint(4, blr);
    shipLeft.setPoint(5, bll);
    shipLeft.setPoint(6, tll);

    shipRight.setPointCount(7);
    shipRight.setPoint(0, trr);
    shipRight.setPoint(1, trl);
    shipRight.setPoint(2, tc);
    shipRight.setPoint(3, bc);
    shipRight.setPoint(4, brl);
    shipRight.setPoint(5, brr);
    shipRight.setPoint(6, trr);

    engine::GameObject::init(game);
    game->getCollisionPool()->push(this);
}

void Netflix::update(engine::Game *game) {
    posY += .2 * game->getElapsedTime();
    posX = posX + sin(posY/80);

    if (posY > game->getRenderTarget()->getView().getSize().y + 30) {
        destroy(game);
    }

    if (isDying) {
        dyingProcess -= .8 * game->getElapsedTime();
    }

    if (dyingProcess <= 0) {
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
    if (isDying) {
        return;
    }

    if(auto* projectile = dynamic_cast<Projectile*>(collidable)) {
        projectile->destroy(game);
        isDying = true;
    }
}
