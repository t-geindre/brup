#include <iostream>
#include "Playing.h"
#include "../Weapons/LaserMachineGun.h"
#include "../Backgrounds/Stars.h"
#include "../Enemies/Netflix.h"

using namespace brup::scenes;
using namespace brup::player;
using namespace brup::weapons;
using namespace brup::backgrounds;
using namespace brup::enemies;

void Playing::init(engine::Game *game) {
    Ship *ship = new Ship;

    LaserMachineGun *weapon = new LaserMachineGun;
    ship->setWeapon(weapon);

    Stars *stars = new Stars;

    game->addObject(stars);
    game->addObject(weapon);
    game->addObject(ship);

    engine::GameObject::init(game);
}

void Playing::update(engine::Game *game) {
    if (starting > 0) {
        starting -= .05 * game->getElapsedTime();
        return;
    }

    if (lastSpawnElapsedTime < spawnRate) {
        lastSpawnElapsedTime += game->getElapsedTime();
        return;
    }
    lastSpawnElapsedTime = 0;
    game->addObject(new Netflix);
}

void Playing::draw(sf::RenderTarget *target) {
    if (starting > 0) {
        sf::RectangleShape fade(target->getView().getSize());
        fade.setPosition(0,0);
        fade.setFillColor(sf::Color(255, 255, 255, starting * 2.55));
        target->draw(fade);
    }
}
