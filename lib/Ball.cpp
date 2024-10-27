#include "Ball.h"
#include <random>

Ball::Ball(){

}

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

void Ball::setVelocity(Vector2 &newVelocity){
    velocity = newVelocity;
}

void Ball::move(){
    shape.setPosition(shape.getPosition().x+velocity.x, shape.getPosition().y+velocity.y);
}

float Ball::getMass() const{
    return mass;
}

float Ball::getRadius() const{
    return radius;
}

sf::CircleShape Ball::getShape() const{
    return shape;
}