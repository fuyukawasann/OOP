//
// Created by 이한별 on 24. 10. 16.
//

#include <iostream>
#include "Triangle.h"
#include "Shape.h"

using namespace std;

// Setter

Triangle& Triangle::setHeight(float newHeight)
{
    height = newHeight;

    return *this;
}


Triangle& Triangle::setWidth(float newWidth)
{
    width = newWidth;

    return *this;
}

Triangle& Triangle::setBottom(float newBottom)
{
    bottom = newBottom;

    return *this;
}

Triangle& Triangle::setLeft(float newLeft)
{
    left = newLeft;

    return *this;
}

void Triangle::setColor(int newColor)
{
    if(newColor != RED) cout << "Triangles are always Red" << endl;

    color = RED;
}



// Getter
float Triangle::getHeight() const
{
    return height;
}

float Triangle::getWidth() const
{
    return width;
}

float Triangle::getBottom() const
{
    return bottom;
}

float Triangle::getLeft() const
{
    return left;
}

float Triangle::getArea() const
{
    return (height * width) / 2;
}
