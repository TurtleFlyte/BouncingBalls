/*
 * Renderer that renders all balls in ballVector using SFML window
 */

#ifndef BOUNCINGBALLS_RENDERER_H
#define BOUNCINGBALLS_RENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "Ball.h"

class Renderer {
private:
    sf::RenderWindow *window;
public:
    Renderer(sf::RenderWindow *window);

    void renderBalls(const std::vector<Ball> &ballVector);
};

#endif //BOUNCINGBALLS_RENDERER_H
