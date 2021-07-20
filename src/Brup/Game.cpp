#include <iostream>
#include "Game.h"
#include "Scenes/Playing.h"
#include "Scenes/StageTitle.h"

using namespace brup;

Game::Game() : engine::Game() {
    enableDebug();
    init("B/R'UP");
    getEventDispatcher()->addListener(engine::Event::NAME, [&](engine::Event *event) {
        std::cout << "kill" << std::endl;
    });
    addObject(new brup::scenes::StageTitle());
    run();
}