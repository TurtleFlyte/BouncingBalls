#include <SFML/Graphics.hpp>

// Vector2 Ball Simulator Renderer

#include "../lib/Simulator.h"
#include "../lib/Renderer.h"

int main()
{
    auto window = sf::RenderWindow({960u, 720u}, "CMake SFML Project");
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

            // Check if left mouse button is being pressed
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    // Add new ball to simulation
                    Ball newBall(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    sim.addBall(newBall);
                }
            }
        }

        // Update all ball velocities and positions
        sim.updatePositions();

        window.clear();

        // Send balls to renderer to be rendered
        renderer.renderBalls(sim.getBallVector());

        window.display();
    }
}
