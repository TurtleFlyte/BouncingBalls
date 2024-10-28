# Ball Elastic Collision with SFML

This c++ project implements perfect elastic collision with graphics handled using SFML. Elastic collision is calculated using [this](https://en.wikipedia.org/wiki/Elastic_collision#:~:text=In%20an%20angle%2Dfree%20representation%2C%20the%20changed%20velocities%20are%20computed%20using%20the%20centers%20x1%20and%20x2%20at%20the%20time%20of%20contact%20as) vector formula and implemented with a custom 2D vector class. 

Built using the [SFML CMake template](https://github.com/SFML/cmake-sfml-project)

## Getting Started

### Prerequisites

1. C++ compiler
2. CMake

### Installation

1. Clone this GitHub reop
   
   ```
   git clone https://github.com/TurtleFlyte/BouncingBalls
   ```
1. Configure and build your project
    Run these commands in the root directory of the project.

    ```
    cmake -B build
    cmake --build build
    ```
1. Run project
   
    ```
    ./build/bin/main
    ```
1. More balls can be spawned by clicking anywhere in the window. Enjoy!

## License

The source code is dual licensed under Public Domain and MIT.
