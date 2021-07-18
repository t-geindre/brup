#ifndef GAME_SHIP_H
#define GAME_SHIP_H

#include <SFML/Graphics/RenderTarget.hpp>
#include "../Weapons/Weapon.h"
#include "../../Engine/GameObject.h"
#include "../../Engine/Collision/Collidable.h"

namespace brup::player {
    class Ship : public engine::GameObject, public engine::Collidable {
        public:
            void draw(sf::RenderTarget *target) override;
            void update(engine::Game *game) override;
            void setMovements(int x, int y);
            void setWeapon(brup::weapons::Weapon *weapon);
            void init(engine::Game *game) override;
            engine::CollisionMask getCollisionMask() override;
            void collisionWith(Collidable *collidable, engine::Game *game) override;
            void destroy(engine::Game *game) override;
            void animateDestruction(engine::Game *game);
            void resetPosition(engine::Game *game);
        private:
            float posX, posY;
            int xMove, yMove;
            bool dead = false;
            int deathRecovery, invincible;
            brup::weapons::Weapon *weapon;
            sf::ConvexShape ship;
            sf::Color shipColor;
    };
}

#endif //GAME_SHIP_H
