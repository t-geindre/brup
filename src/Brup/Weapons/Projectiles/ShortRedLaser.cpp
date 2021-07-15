#include <SFML/Graphics/RectangleShape.hpp>
#include "ShortRedLaser.h"

using namespace brup::weapons::projectiles;

ShortRedLaser::ShortRedLaser() {
    this->yVelocity = -1.1;
}

void ShortRedLaser::draw(sf::RenderTarget *target) {
    sf::RectangleShape laser(sf::Vector2f(4, 12));
    laser.setFillColor(sf::Color(50, 255, 50));
    laser.setPosition(xPosition - 22, yPosition);
    target->draw(laser);
    laser.setPosition(xPosition + 17 , yPosition);
    target->draw(laser);
}

engine::CollisionMask ShortRedLaser::getCollisionMask() {
    return engine::CollisionMask {
        xPosition - 22,
        yPosition,
        39,
        12
    };
}
