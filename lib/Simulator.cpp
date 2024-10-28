#include "Simulator.h"
#include <iostream>

void Simulator::checkForBallCollision(Ball &ball1, Ball &ball2){
    // Get both ball positions
    Vector2 pos1 = {ball1.getShape().getPosition().x + ball1.getRadius(), ball1.getShape().getPosition().y + ball1.getRadius()};
    Vector2 pos2 = {ball2.getShape().getPosition().x + ball2.getRadius(), ball2.getShape().getPosition().y + ball2.getRadius()};

    float m1 = ball1.getMass();
    float m2 = ball2.getMass();

    Vector2 v1 = ball1.getVelocity();
    Vector2 v2 = ball2.getVelocity();

    // Get distance between the two balls
    float distance = sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));

    // Collision is happening if distance is less than the sum of both radii
    if(distance < ball1.getRadius()+ball2.getRadius()){
        // Calculate ball1's velocity vector
        Vector2 ball1Velocity = ball1.getVelocity()
                                -((pos1 - pos2)
                                  *((2* m2) / (m1 + m2))
                                  *(((v1-v2)*(pos1 - pos2)) / ((pos1 - pos2).getMagnitude() * (pos1 - pos2).getMagnitude())));

        // Calculate ball2's velocity vector
        Vector2 ball2Velocity = ball2.getVelocity()
                                -((pos2 - pos1)
                                  *((2* m1) / (m1 + m2))
                                  *(((v2-v1)*(pos2 - pos1)) / ((pos2 - pos1).getMagnitude() * (pos2 - pos1).getMagnitude())));

        // Set both balls velocities
        ball1.setVelocity(ball1Velocity);
        ball2.setVelocity(ball2Velocity);

        ball1.getShape().setPosition(ball1.getLastGoodPos().x, ball1.getLastGoodPos().y);
        ball2.getShape().setPosition(ball2.getLastGoodPos().x, ball2.getLastGoodPos().y);
    }
}

void Simulator::checkForWallCollision(Ball &ball){
    // Get balls position and velocity
    Vector2 ballVelocity = ball.getVelocity();
    Vector2 ballPos = {ball.getShape().getPosition().x+ball.getRadius(), ball.getShape().getPosition().y+ball.getRadius()};

    // Transform velocity based on wall hit
    if(ballPos.y < ball.getRadius() || ballPos.y > 720-ball.getRadius()) {
        ballVelocity.y *= -1.f;
    }
    if(ballPos.x < ball.getRadius() || ballPos.x > 960-ball.getRadius()) {
        ballVelocity.x *= -1.f;
    }

    // Set velocity
    ball.setVelocity(ballVelocity);

    ball.getShape().setPosition(ball.getLastGoodPos().x, ball.getLastGoodPos().y);
}

Simulator::Simulator(){
    Ball startingBall(300,300);

    addBall(startingBall);
}

void Simulator::updatePositions(){
    for (int i = 0; i < ballVector.size()-1; ++i) {
        // Move each ball
        ballVector[i].move();

        // Check for collision between each unique pair of balls
        for (int j = i+1; j < ballVector.size(); ++j) {
            checkForBallCollision(ballVector[i],ballVector[j]);
        }

        // Check for collision between each ball and wall
        checkForWallCollision(ballVector[i]);
    }

    // Move the last ball
    ballVector[ballVector.size()-1].move();

    // Check for collision between last ball and wall
    checkForWallCollision(ballVector[ballVector.size()-1]);
}

void Simulator::addBall(const Ball &newBall){
    ballVector.push_back(newBall);
}

std::vector<Ball> Simulator::getBallVector(){
    return ballVector;
}