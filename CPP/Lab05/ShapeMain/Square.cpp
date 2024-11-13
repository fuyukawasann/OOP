// Square.cpp
// This class describes a Square

#include <iostream>
#include "Square.h"

using namespace std;

int Square::count = 0;

// Constructor for Square
Square::Square()
{
    count++;
    setSideLength(count);
    cout << "Creating Square with Side Length " << getSideLength() << endl;
}

// Copy Constructor for Square
Square::Square(const Square& copyFrom)
{
    count++;
    setSideLength(copyFrom.getSideLength());
    cout << "Copying Square with Side Length " << getSideLength() << endl;
}

// Destructor for Square
Square::~Square()
{
    count--;
    cout << "Destroying Square with Side Length " << getSideLength() << endl;
}

// Assignment Operator for Square
Square & Square::operator=(const Square & copyFrom)
{
    setSideLength(copyFrom.getSideLength());
    cout << "Assigning Square with Side Length " << copyFrom.getSideLength() << endl;

    return *this;
}

Square& Square::setCenter(float newX, float newY)
{
    centerX = newX;
    centerY = newY;

    return *this;
}

Square& Square::setSideLength(float newSideLength)
{
    if(newSideLength >= 0) sideLength = newSideLength;
    else cout << "Error: side length should be >= 0" << endl;

    return *this;
}

Square& Square::setX(float newX)
{
    centerX = newX;

    return *this;
}

Square& Square::setY(float newY)
{
    centerY = newY;

    return *this;
}


float Square::getX() const
{
    return centerX;
}

float Square::getY() const
{
    return centerY;
}

float Square::getSideLength() const
{
    return sideLength;
}

float Square::getArea() const
{
    return sideLength * sideLength;
}

int Square::getCount()
{
    return count;
}


