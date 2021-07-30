#include "Stars.h"
#include "../Events/SceneEnds.h"

using namespace brup::backgrounds;
using namespace brup::events;

void Stars::init(engine::Game *game) {
    for(int i = 0 ; i < starsCount ; i++) {
        resetStar(i, game);
    }

    GameObject::init(game);
}

void Stars::draw(sf::RenderTarget *target) {
    sf::RectangleShape star(sf::Vector2f(2, 2));

    for(int i = 0 ; i < starsCount ; i++) {
        star.setPosition(stars[i].posX, stars[i].posY);
        star.setFillColor(sf::Color(
                25 * stars[i].brightness,
                25 * stars[i].brightness,
                25 * stars[i].brightness
                ));
        target->draw(star);
    }
}

void Stars::update(engine::Game *game) {
    float maxY = game->getRenderTarget()->getView().getSize().y;
    for(int i = 0 ; i < starsCount ; i++) {
        stars[i].posY += 0.1 * stars[i].depth * game->getElapsedTime();
        if (stars[i].posY > maxY) {
            resetStar(i, game, true);
        }
    }
}

void Stars::resetStar(int star, engine::Game *game, bool top) {
    int maxX = (int) game->getRenderTarget()->getView().getSize().x;
    int maxY = (int) game->getRenderTarget()->getView().getSize().y;

    stars[star].posX = rand() % maxX;
    stars[star].posY = top ? 0 : rand() % maxY;
    stars[star].brightness = rand() % 10 + 1;
    stars[star].depth = rand() % 9 + 1;
}


