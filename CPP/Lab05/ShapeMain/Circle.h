// Circle.h
// This class describes a Circle


#include "Shape.h"
const float PI = 3.14159;

class Circle: public Shape
{
private:
    float centerX;
    float centerY;
    float radius;
    static int count;
public:
    Circle();
    Circle(const Circle & copyFrom);
    ~Circle();
    Circle & operator=(const Circle & copyFrom);

    // Setters and Getters
    Circle & setCenter(float newX, float newY);
    Circle & setRadius(float newRadius);
    Circle & setX(float newX);
    Circle & setY(float newY);
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getArea() const;
    static int getCount();
};
