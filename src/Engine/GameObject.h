#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "Update/Updatable.h"
#include "Draw/Drawable.h"
#include "Initable.h"
#include <vector>

namespace engine {
    class Game;
    class GameObject: public Updatable, public Drawable, public Initable {
        public:
            void init(Game *game) override;
            void draw(sf::RenderTarget *target) override;
            unsigned int getDrawPriority() override;
            void update(Game *game) override;
            virtual void destroy(Game *game);
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
