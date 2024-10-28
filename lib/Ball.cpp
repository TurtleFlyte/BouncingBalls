#include "Ball.h"
#include <random>

Ball::Ball(float xPos, float yPos){
    std::random_device rd;
    std::mt19937 gen(rd());     // Seed
    // Construct distributions
    std::uniform_real_distribution<float> velocityDis(-2, 2);
    std::uniform_real_distribution<float> massRadiusDis(20, 35);
    std::uniform_int_distribution<int> colorDis(0,255);

    velocity = {velocityDis(gen), velocityDis(gen)};    // Random velocity
    radius = massRadiusDis(gen);            // Random radius
    mass = massRadiusDis(gen);              // Random mass

    // Random color
    sf::Color color(colorDis(gen),colorDis(gen),colorDis(gen), 255);
    shape.setFillColor(color);

    // Set radius and positions
    shape.setRadius(radius);
    shape.setPosition(xPos,yPos);
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