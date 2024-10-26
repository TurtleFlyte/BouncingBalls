/*
 * Defines Ball class which stores:
 *      Velocity
 *      Mass
 *      Radius
 *      SFML shape
 *
 * Implements getters for velocity, mass, radius, and shape
 */

#ifndef CMAKESFMLPROJECT_BALL_H
#define CMAKESFMLPROJECT_BALL_H

#include "Vector2.h"
#include <SFML/Graphics/CircleShape.hpp>

class Ball{
private:
    Vector2 velocity;
    float mass;
    float radius;
    sf::CircleShape shape;
public:
    Ball(float xVel, float yVel, float mass, float radius, float xPos, float yPos);

    Vector2 getVelocity() const;
    float getmass() const;
    float getRadius() const;
    sf::CircleShape getShape() const;
};

#endif //CMAKESFMLPROJECT_BALL_H