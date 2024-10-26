//
// Created by Andrew Polkinhorn on 10/25/24.
//

#include "Ball.h"

Ball::Ball(float xVel, float yVel, float mass, float radius, float xPos, float yPos){
    velocity = {xVel, yVel};
    this->mass = mass;
    this->radius = radius;
    shape.setRadius(this->radius);
    shape.setPosition(xPos, yPos);
}

Vector2 Ball::getVelocity() const{
    return velocity;
}

float Ball::getmass() const{
    return mass;
}

float Ball::getRadius() const{
    return radius;
}

sf::CircleShape Ball::getShape() const{
    return shape;
}