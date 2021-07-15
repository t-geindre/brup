#include "Main.h"
#include "../Weapons/LaserMachineGun.h"
#include "../Backgrounds/Stars.h"
#include "../Enemies/Netflix.h"

using namespace brup::scenes;
using namespace brup::player;
using namespace brup::weapons;
using namespace brup::backgrounds;
using namespace brup::enemies;

void Main::init(engine::Game *game) {
    Ship *ship = new Ship;

    LaserMachineGun *weapon = new LaserMachineGun;
    ship->setWeapon(weapon);

    Stars *stars = new Stars;

    game->addObject(stars);
    game->addObject(weapon);
    game->addObject(ship);
    game->addObject(new Netflix);
}

void Main::update(engine::Game *game) {
    if (lastSpawnElapsedTime < spawnRate) {
        lastSpawnElapsedTime += game->getElapsedTime();
        return;
    }
    lastSpawnElapsedTime = 0;
    game->addObject(new Netflix);
}
