#include <iostream>
#include "Playing.h"
#include "../Enemies/Netflix.h"
#include "../Events/PlayerKilled.h"
#include "../Events/EnemyKilled.h"
#include "../Events/SceneEnds.h"
#include "../Weapons/LaserMachineGun.h"

using namespace brup::scenes;
using namespace brup::player;
using namespace brup::weapons;
using namespace brup::backgrounds;
using namespace brup::enemies;
using namespace brup::events;

void Playing::init(engine::Game *game) {
    stars = new Stars;
    player.weapon = new LaserMachineGun;

    resetShip(game);

    game->addObject(stars);
    game->addObject(player.weapon);

    listeners.push_back(game->getEventDispatcher()->addListener(EnemyKilled::NAME, [&](engine::Event *event) {
        std::cout << "Enemy killed" << std::endl;
    }));

    listeners.push_back(game->getEventDispatcher()->addListener(PlayerKilled::NAME, [&, game](engine::Event *event) {
        player.lives -= 1;
        if (player.lives > 0) {
            player.recoveryProcess = player.recoveryDuration;
            return;
        }
        game->getEventDispatcher()->dispatch(new SceneEnds);
        destroy(game);
    }));

    engine::GameObject::init(game);
}

void Playing::update(engine::Game *game) {
    if (player.recoveryProcess > 0) {
        player.recoveryProcess -= game->getElapsedTime();
        if (player.recoveryProcess <= 0) {
            resetShip(game);
        }
    }

    if (starting > 0) {
        starting -= .08f * game->getElapsedTime();
        return;
    }

    if (enemies.lastSpawnElapsedTime < enemies.spawnRate) {
        enemies.lastSpawnElapsedTime += game->getElapsedTime();
        return;
    }
    enemies.lastSpawnElapsedTime = 0;
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

unsigned int Playing::getDrawPriority() {
    return 1000;
}

void Playing::resetShip(engine::Game *game) {
    player.ship = new Ship;
    player.ship->setWeapon(player.weapon);
    game->addObject(player.ship);
}

void Playing::destroy(engine::Game *game) {
    stars->destroy(game);
    //player.ship->destroy(game);
    GameObject::destroy(game);
}
