#include <cmath>
#include <iostream>
#include "ParticleExplosion.h"

using namespace brup::effects;

void ParticleExplosion::setParticlesSize(float min, float max) {
    minSize = min;
    maxSize = max;
}

void ParticleExplosion::setParticlesVelocity(float min, float max) {
    minVelocity = minVelocity;
    maxVelocity = maxVelocity;
}

void ParticleExplosion::setParticlesFadeSpeed(float min, float max) {
    minFadeSpeed = min;
    maxFadeSpeed = max;
}

void ParticleExplosion::setPosition(float x, float y) {
    posX = x;
    posY = y;
}

void ParticleExplosion::setParticlesCount(int count) {
    particlesCount = count;
}

void ParticleExplosion::pushParticlesColor(sf::Color color) {
    colors.push_back(color);
}

void ParticleExplosion::init(engine::Game *game) {
    if (colors.size() == 0) {
        colors.push_back(sf::Color(255, 255, 255));
    }

    for (int i = 0; i < particlesCount; i++) {
        float velocity = minVelocity == maxVelocity ? minVelocity : minVelocity + (float) (rand()) / ((float) (RAND_MAX / (maxVelocity - minVelocity)));
        float size = minSize == maxSize ? minSize : minSize + (float) (rand()) / ((float) (RAND_MAX / (maxSize - minSize)));
        float fadeSpeed = minFadeSpeed == maxFadeSpeed ? minFadeSpeed : minFadeSpeed + (float) (rand()) / ((float) (RAND_MAX / (maxFadeSpeed - minFadeSpeed)));
        float direction = (float) (2 * M_PI * rand())/RAND_MAX;

        auto* particule = new Particle {
            posX,
            posY,
            colors[rand() % colors.size()],
            velocity * (float) cos(direction),
            velocity * (float) sin(direction),
            100,
            fadeSpeed,
            size
        };

        particles.push_back(particule);
    }

    engine::GameObject::init(game);
}

void ParticleExplosion::update(engine::Game *game) {
    for (int i = 0; i < particles.size(); i++) {
        auto* particle = particles[i];
        particle->posX += particle->xVelocity * game->getElapsedTime();
        particle->posY += particle->yVelocity * game->getElapsedTime();
        particle->fade -= particle->fadeSpeed * game->getElapsedTime();
        particle->color.a = particle->fade * 2.55;
        if (particle->fade < 0) {
            particles.erase(particles.begin()+i);
            delete particle;
        }
    }

    if (particles.size() == 0) {
        this->destroy(game);
    }
}

void ParticleExplosion::draw(sf::RenderTarget *target) {
    sf::RectangleShape shape;
    for (int i = 0; i < particles.size(); i++) {
        auto* particle = particles[i];
        shape.setPosition(particle->posX, particle->posY);
        shape.setSize(sf::Vector2f(particle->size, particle->size));
        shape.setFillColor(particle->color);
        target->draw(shape);
    }
}

