#include "Vector2.h"

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y){
    this->x = x;
    this->y = y;
}

float Vector2::getMagnitude() const{
    return sqrt(x*x+y*y);
}

Vector2 Vector2::normalize() const{
    float magnitude = getMagnitude();
    return {x/magnitude, y/magnitude};
}

float Vector2::operator*(Vector2 const &other) const{
    return x*other.x + y*other.y;
}

Vector2 Vector2::operator*(float const &other) const{
    return {x*other, y*other};
}

Vector2 Vector2::operator-(Vector2 const &other) const{
    return {x-other.x,y-other.y};
}