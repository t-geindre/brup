#ifndef GAME_PARTICLEEXPLOSION_H
#define GAME_PARTICLEEXPLOSION_H

#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "../../Engine/GameObject.h"
#include "../../Engine/Game.h"

namespace brup::effects {

    struct Particle {
        float posX;
        float posY;
        sf::Color color;
        float xVelocity;
        float yVelocity;
        float fade;
        float fadeSpeed;
        float size;
    };

    class ParticleExplosion : public engine::GameObject {
        public:
            void setParticlesSize(float min, float max);
            void setParticlesVelocity(float min, float max);
            void setParticlesFadeSpeed(float min, float max);
            void setParticlesCount(int count);
            void pushParticlesColor(sf::Color color);
            void setPosition(float x, float y);
            void init(engine::Game *game) override;
            void update(engine::Game *game) override;
            void draw(sf::RenderTarget *target) override;
        private:
            float minVelocity = .005;
            float maxVelocity = .2;
            float minSize = 1;
            float maxSize = 1;
            float minFadeSpeed = .05;
            float maxFadeSpeed = .08;
            float posX = 0;
            float posY = 0;
            int particlesCount = 100;
            std::vector<sf::Color> colors;
            std::vector<Particle*> particles;
    };
}

#endif //GAME_PARTICLEEXPLOSION_H
