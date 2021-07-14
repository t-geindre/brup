#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include "DrawPool.h"
#include "UpdatePool.h"
#include "Initable.h"
#include "Scene.h"

namespace engine {
    class Game {
        public:
            Game();
            void init(std::string title);
            void loadScene(Scene *scene);
            Scene* getScene();
            sf::RenderTarget* getRenderTarget();
            UpdatePool* getUpdatePool();
            DrawPool* getDrawPool();
            int getElapsedTime();
            void addObject(Initable *initable);

        protected:
            void handleEvents();
            void update();
            void draw();
            void run();
            void updateElapsedTime();

        private:
            Scene *scene;
            sf::RenderWindow *window;
            sf::Clock *clock;
            DrawPool *drawPool;
            UpdatePool *updatePool;
            bool quit = false;
            int elapsedTime = 0;
    };
}

#endif //GAME_GAME_H
