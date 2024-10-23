// Circle.cpp
// This class describes a Circle

#include <iostream>
#include "Circle.h"

using namespace std;

int Circle::count = 0;

// Constructor for Circle
Circle::Circle()
{
    count++;
    setRadius(count);
    cout << "Creating Circle with Radius " << getRadius() << endl;
}

// Copy Constructor for Circle
Circle::Circle(const Circle & copyFrom)
{
    count++;
    setRadius(copyFrom.getRadius());
    cout << "Copying Circle with Radius " << copyFrom.getRadius() << endl;
}

// Destructor for Circle
Circle::~Circle()
{
    count--;
    cout << "Destroying Circle with Radius " << getRadius() << endl;
}

// Assignment Operator for Circle
Circle & Circle::operator=(const Circle & copyFrom)
{
    setRadius(copyFrom.getRadius());
    cout << "Assigning Circle with Radius " << copyFrom.getRadius() << endl;

    return *this;
}

// This function changes the center of the circle to a new location
Circle & Circle::setCenter(float newX, float newY)
{
    centerX = newX;
    centerY = newY;

    return *this;
}

// This function changes the radius of the circle.
Circle& Circle::setRadius(float newRadius)
{
    if(newRadius >= 0) radius = newRadius;
    else cout << "Error: radius should be >= 0" << endl;

    return *this;
}

Circle& Circle::setX(float newX)
{
    centerX = newX;

    return *this;
}

Circle& Circle::setY(float newY)
{
    centerY = newY;

    return *this;
}


// This function returns the X coordinate of the center of the circle
float Circle::getX() const
{
    return centerX;
}

// This function returns the Y coordinate of the center of the circle
float Circle::getY() const
{
    return centerY;
}

// This function returns the radius of the circle
float Circle::getRadius() const
{
    return radius;
}

// This function returns the area of the circle
float Circle::getArea() const
{
    return radius * radius * PI;
}

// This function returns the count of how many circles exist
int Circle::getCount()
{
    return count;
}

