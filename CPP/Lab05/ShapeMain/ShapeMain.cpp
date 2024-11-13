// ShapeMain.cpp

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

Square *makeSquare()
{
    Square * square1 = new Square;
    float sideLength;

    cout << "What is the Side Length? ";
    cin >> sideLength;

    square1->setSideLength(sideLength).setX(0).setY(0);

    return square1;
}

Circle *makeCircle()
{
    Circle * circle1 = new Circle;
    float radius;

    cout << "What is the Radius? ";
    cin >> radius;
    circle1->setRadius(radius).setX(0).setY(0);

    return circle1;
}

Triangle *makeTriangle()
{
    Triangle * triangle1 = new Triangle;
    float height, width;

    cout << "What is the Height? ";
    cin >> height;
    cout << "What is the Width? ";
    cin >> width;
    triangle1->setHeight(height).setWidth(width);

    return triangle1;
}

int makeColor()
{
    int color;

    cout << RED << ") Red or " << BLUE << ") Blue or " <<  GREEN << ") Green? ";
    cin >> color;

    return color;
}

int main()
{
    Shape * shape1;
    int color;

    int shapeType;

    cout << "1) Square or 2) Circle or 3) Triangle? ";
    cin >> shapeType;

    switch (shapeType)
    {
        case 1: shape1 = makeSquare(); break;
        case 2: shape1 = makeCircle(); break;
        case 3: shape1 = makeTriangle(); break;
        default: throw runtime_error("Invalid Shape Class");
    }

    color = makeColor();
    shape1->setColor(color);

    cout << "The Area is " << shape1->getArea() << endl;
    cout << "The Color is ";
    shape1->printColor();
    cout << endl;

    return 0;
}