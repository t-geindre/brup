#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "Game.h"
#include <vector>

namespace engine {
    class GameObject {
        public:
            void init(Game *game);
            void draw();
            unsigned int getDrawPriority();
            void update();
            void destroy();
            void doDestroy();
            void setPosition(sf::Vector2f position);
            void setPosition(float x, float y);
            void setSize(sf::Vector2f size);
            void setSize(float x, float y);
            sf::Vector2f getPosition();
            sf::Vector2f getSize();
        protected:
            sf::Vector2f position;
            sf::Vector2f size;
            std::vector<uint> listeners;
    };
}

#endif //GAME_GAMEOBJECT_H
