#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "Ship.h"

using namespace brup::player;
using namespace brup::weapons;

void Ship::draw(sf::RenderTarget *target) {

    sf::Vector2f topSpike(0, -35);
    sf::Vector2f leftCavity(-10, 0);
    sf::Vector2f rightCavity(10, 0);
    sf::Vector2f leftSpike(-22, 20);
    sf::Vector2f rightSpike(22, 20);
    sf::Vector2f bottomCavity(0, 10);

    sf::ConvexShape ship;
    ship.setPointCount(6);
    ship.setPoint(0, topSpike);
    ship.setPoint(1, leftCavity);
    ship.setPoint(2, leftSpike);
    ship.setPoint(3, bottomCavity);
    ship.setPoint(4, rightSpike);
    ship.setPoint(5, rightCavity);
    ship.setPoint(6, topSpike);

    ship.setPosition(posX, posY);
    // ship.setOutlineThickness(1);
    // ship.setOutlineColor(sf::Color(255, 108, 89));
    ship.setFillColor(sf::Color(251, 87, 66));

    target->draw(ship);
  }

void Ship::setMovements(int x, int y)
{
    xMove = x;
    yMove = y;
}

void Ship::update(engine::Game *game)
{
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

    posX = game->getRenderTarget()->getView().getCenter().x;
    posY = game->getRenderTarget()->getView().getSize().y - 40.f;

    xMove = 0;
    yMove = 0;

    engine::GameObject::init(game);
}
