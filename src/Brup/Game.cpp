#include "Game.h"
#include "Scenes/Playing.h"
#include "Scenes/StageTitle.h"

using namespace brup;

Game::Game() : engine::Game() {
    enableDebug();
    init("B/R'UP");
    addObject(new brup::scenes::StageTitle());
    run();
}