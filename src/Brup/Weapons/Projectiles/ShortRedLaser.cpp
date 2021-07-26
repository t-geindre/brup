#include <SFML/Graphics/RectangleShape.hpp>
#include "ShortRedLaser.h"

using namespace brup::weapons::projectiles;

ShortRedLaser::ShortRedLaser() {
    this->yVelocity = -1.1;
}

void ShortRedLaser::draw(sf::RenderTarget *target) {
    sf::RectangleShape laser(sf::Vector2f(4, 12));
    laser.setFillColor(sf::Color(50, 255, 50));
    laser.setPosition(position.x - 22, position.y);
    target->draw(laser);
    laser.setPosition(position.x + 17 , position.y);
    target->draw(laser);
}

engine::CollisionMask ShortRedLaser::getCollisionMask() {
    return engine::CollisionMask {
        position.x - 22,
        position.y,
        39,
        12
    };
}
