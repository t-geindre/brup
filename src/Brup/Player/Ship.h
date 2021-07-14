#ifndef GAME_SHIP_H
#define GAME_SHIP_H

#include <SFML/Graphics/RenderTarget.hpp>
#include "../Weapons/Weapon.h"
#include "../../Engine/GameObject.h"

namespace brup::player {
    class Ship : public engine::GameObject {
        public:
            void draw(sf::RenderTarget *target) override;
            void update(engine::Game *game) override;
            void setMovements(int x, int y);
            void setWeapon(brup::weapons::Weapon *weapon);
            void init(engine::Game *game) override;
        private:
            float posX, posY;
            int xMove, yMove;
            brup::weapons::Weapon *weapon;
    };
}

#endif //GAME_SHIP_H
