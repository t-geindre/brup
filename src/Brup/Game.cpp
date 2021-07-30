#include "Game.h"
#include "Scenes/Playing.h"
#include "Scenes/StageTitle.h"
#include "Events/SceneEnds.h"

using namespace brup;
using namespace brup::events;


Game::Game() : engine::Game() {
    // enableDebug();
    init("B/R'UP");

    getEventDispatcher()->addListener(SceneEnds::NAME, [&](engine::Event *event) {
        this->nextState();
    });

    this->state = Game::STATES::NONE;
    this->nextState();

    run();
}

void Game::nextState() {
    switch (this->state) {

        case Game::STATES::NONE:
        case Game::STATES::PLAYING:
            this->state = Game::STATES::STAGE_TITLE;
            addObject(new brup::scenes::StageTitle());
            break;

        case Game::STATES::STAGE_TITLE:
            this->state = Game::STATES::PLAYING;
            addObject(new brup::scenes::Playing());
            break;
    }
}
