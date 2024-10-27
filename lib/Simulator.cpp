#include "Simulator.h"
#include <iostream>

void Simulator::checkForBallCollision(Ball &ball1, Ball &ball2){
    // Collision with other ball
    Vector2 ball1Pos = {ball1.getShape().getPosition().x+ball1.getRadius(), ball1.getShape().getPosition().y+ball1.getRadius()};
    Vector2 ball2Pos = {ball2.getShape().getPosition().x+ball2.getRadius(), ball2.getShape().getPosition().y+ball2.getRadius()};

    float distance = sqrt((ball1Pos.x-ball2Pos.x)*(ball1Pos.x-ball2Pos.x) + (ball1Pos.y-ball2Pos.y)*(ball1Pos.y-ball2Pos.y));

    if(distance < ball1.getRadius()+ball2.getRadius()){
        Vector2 ball1Velocity = ball1.getVelocity()
                -((ball1Pos-ball2Pos)
                *((2* ball2.getMass()) / (ball1.getMass() + ball2.getMass()))
                *(((ball1.getVelocity()-ball2.getVelocity())*(ball1Pos-ball2Pos))/((ball1Pos-ball2Pos).getMagnitude()*(ball1Pos-ball2Pos).getMagnitude())));

        Vector2 ball2Velocity = ball2.getVelocity()
                                -((ball2Pos-ball1Pos)
                                  *((2* ball1.getMass()) / (ball1.getMass() + ball2.getMass()))
                                  *(((ball2.getVelocity()-ball1.getVelocity())*(ball2Pos-ball1Pos))/((ball2Pos-ball1Pos).getMagnitude()*(ball2Pos-ball1Pos).getMagnitude())));

        ball1.setVelocity(ball1Velocity);
        ball2.setVelocity(ball2Velocity);
    }
}

void Simulator::checkForWallCollision(Ball &ball){
    Vector2 ballVelocity = ball.getVelocity();
    Vector2 ballPos = {ball.getShape().getPosition().x+ball.getRadius(), ball.getShape().getPosition().y+ball.getRadius()};

    if(ballPos.y < ball.getRadius()) ballVelocity = {ballVelocity.x, -ballVelocity.y};
    if(ballPos.x < ball.getRadius()) ballVelocity = {-ballVelocity.x, ballVelocity.y};
    if(ballPos.y > 480-ball.getRadius()) ballVelocity = {ballVelocity.x, -ballVelocity.y};
    if(ballPos.x > 640-ball.getRadius()) ballVelocity = {-ballVelocity.x, ballVelocity.y};

    ball.setVelocity(ballVelocity);
}

Simulator::Simulator() {
    Ball ball1(5,3.5,20,15,200,200);
    Ball ball2(-8,4,20,20,300,300);
    Ball ball3(5,3.5,20,15,190 ,200);

    ballVector.push_back(ball1);
    ballVector.push_back(ball2);
    ballVector.push_back(ball3);
}

//Simulator::Simulator(int numberOfBalls){
//    for (int i = 0; i < numberOfBalls; ++i) {
//        ballVector.emplace_back(Ball());
//    }
//}

void Simulator::updatePositions(){
    for (int i = 0; i < ballVector.size()-1; ++i) {
        for (int j = i+1; j < ballVector.size(); ++j) {
            checkForBallCollision(ballVector[i],ballVector[j]);
        }

        checkForWallCollision(ballVector[i]);
        ballVector[i].move();
    }

    checkForWallCollision(ballVector[ballVector.size()-1]);
    ballVector[ballVector.size()-1].move();
}

void Simulator::addBall(const Ball &newBall){
    ballVector.push_back(newBall);
}

std::vector<Ball> Simulator::getBallVector(){
    return ballVector;
}