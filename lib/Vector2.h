/*
 * Custom Vector2 class with functionality like:
 *      Normalizing
 *      Magnitude
 *      Dot product
 *      Subtraction
 *
 * x and y variables can be accessed directly
 */

#ifndef BOUNCINGBALLS_VECTOR2_H
#define BOUNCINGBALLS_VECTOR2_H

#include <cmath>

class Vector2{
public:
    float x, y;

    Vector2();
    Vector2(float x, float y);

    float getMagnitude() const;     // Returns magnitude of the vector
    Vector2 normalize() const;      // Returns a normalized version of the vector
    float operator*(Vector2 const &other) const;        // Returns the dot product of vector and reference other
    Vector2 operator*(float const &other) const;        // Returns the vector of vector scalar mulitplication
    Vector2 operator-(Vector2 const &other) const;      // Subtracts vector components then returns a vector
};

#endif //BOUNCINGBALLS_VECTOR2_H