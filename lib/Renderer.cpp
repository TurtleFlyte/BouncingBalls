#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow *window){
    this->window = window;
}

void Renderer::renderBalls(const std::vector<Ball> &ballVector){
    window->clear();

    for (const Ball& ball:ballVector) {
        window->draw(ball.getShape());
    }

    window->display();
}