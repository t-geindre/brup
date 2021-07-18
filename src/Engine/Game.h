#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Draw/DrawPool.h"
#include "Update/UpdatePool.h"
#include "Initable.h"
#include "Collision/CollisionPool.h"
#include "GameObject.h"

namespace engine {
    class Game {
        public:
            Game();
            void init(std::string title);
            sf::RenderTarget* getRenderTarget();
            UpdatePool* getUpdatePool();
            DrawPool* getDrawPool();
            CollisionPool* getCollisionPool();
            int getElapsedTime();
            void addObject(Initable *initable);
            void enableDebug();

        protected:
            void handleEvents();
            virtual void update();
            void draw();
            void run();
            void updateElapsedTime();

        private:
            sf::RenderWindow *window;
            sf::Clock *clock;
            DrawPool *drawPool;
            UpdatePool *updatePool;
            CollisionPool *collisionPool;
            bool quit = false;
            int elapsedTime = 0;
            bool debugEnabled = false;
            GameObject *debugObjects[2];
    };
}

#endif //GAME_GAME_H
