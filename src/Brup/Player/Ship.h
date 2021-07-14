#ifndef GAME_SHIP_H
#define GAME_SHIP_H

#include <SFML/Graphics/RenderTarget.hpp>
#include "../../Engine/Drawable.h"
#include "../../Engine/Updatable.h"
#include "../../Engine/Initable.h"
#include "../Weapons/Weapon.h"

namespace brup::player {
    class Ship : public engine::Drawable, public engine::Updatable, public engine::Initable {
        public:
            void draw(sf::RenderTarget *target);
            void update(engine::Game *game);
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
