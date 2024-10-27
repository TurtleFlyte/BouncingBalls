#include <SFML/Graphics.hpp>

// Vector2 Ball Simulator Renderer

#include "../lib/Simulator.h"
#include "../lib/Renderer.h"

int main()
{
    auto window = sf::RenderWindow({640u, 480u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    Simulator sim;
    Renderer renderer(&window);

    while (window.isOpen())
    {
        for (auto event = sf::Event(); window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sim.updatePositions();

        window.clear();

        renderer.renderBalls(sim.getBallVector());

        window.display();
    }
}
