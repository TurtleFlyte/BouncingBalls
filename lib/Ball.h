/*
 * Defines Ball class which stores:
 *      Velocity
 *      Mass
 *      Radius
 *      SFML shape
 *
 * Implements getters for velocity, mass, radius, and shape
 *      Setter for velocity
 */

#ifndef BOUNCINGBALLS_BALL_H
#define BOUNCINGBALLS_BALL_H

#include "Vector2.h"
#include <SFML/Graphics/CircleShape.hpp>

class Ball{
private:
    Vector2 velocity;
    float mass;
    float radius;
    sf::CircleShape shape;
    Vector2 lastGoodPos;

public:
    Ball(float xPos, float yPos);   // Random ball constructor
    Ball(float xVel, float yVel, float mass, float radius, float xPos, float yPos);

    Vector2 getVelocity() const;
    void setVelocity(Vector2 &newVelocity);
    void move();        // Changes ball position based on velocity

    float getMass() const;
    float getRadius() const;
    sf::CircleShape getShape() const;
    Vector2 getLastGoodPos() const;
};

#endif //BOUNCINGBALLS_BALL_H