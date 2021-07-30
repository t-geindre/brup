#ifndef GAME_PLAYING_H
#define GAME_PLAYING_H

#include "../../Engine/GameObject.h"
#include "../Player/Ship.h"
#include "../Weapons/Weapon.h"
#include "../Backgrounds/Stars.h"

namespace brup::scenes {
    class Playing : public engine::GameObject {
        public:
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            void draw(sf::RenderTarget *target) override;
            unsigned int getDrawPriority() override;
            void destroy(engine::Game *game) override;
            void resetShip(engine::Game *game);
        private:
            float starting = 100;
            struct {
                unsigned int score = 0;
                int lives = 3;
                int recoveryProcess = 0;
                int recoveryDuration = 3000;
                brup::player::Ship *ship;
                brup::weapons::Weapon *weapon;
            } player;
            struct {
                int spawnRate = 200;
                int lastSpawnElapsedTime = 0;
            } enemies;
            brup::backgrounds::Stars *stars;
    };
}

#endif //GAME_PLAYING_H
