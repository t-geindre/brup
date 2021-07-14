#include "Game.h"
#include "Scenes/Main.h"

using namespace brup;

Game::Game() : engine::Game() {
    init("B/R'UP");
    loadScene(new brup::scenes::Main());
    run();
}
