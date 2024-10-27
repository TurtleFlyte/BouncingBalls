/*
 * Defines a simulator class which holds a vector of all balls and:
 *      Updates position of all balls
 *      Checks for a collision between all balls
 */

#ifndef BOUNCINGBALLS_SIMULATOR_H
#define BOUNCINGBALLS_SIMULATOR_H

#include <vector>
#include "Ball.h"

class Simulator{
private:
    std::vector<Ball> ballVector;

    void checkForBallCollision(Ball &ball1, Ball &ball2);       // Checks for collision between two balls and updates velocities
    void checkForWallCollision(Ball &ball);                     // Checks for collision on wall
public:
    Simulator();
//    Simulator(int numberOfBalls);

    void updatePositions();     // Updates the position of each ball based on velocity after a possible collision
    void addBall(const Ball &newBall);
    std::vector<Ball> getBallVector();
};

#endif //BOUNCINGBALLS_SIMULATOR_H
