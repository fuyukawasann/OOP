// SquareMain.cpp

#include <iostream>
#include "Square.h"

using namespace std;

float calculateTotalArea(Square * squareArray)
{
    int index;
    float total = 0;

    for(index = 0; index < Square::getCount(); index++)
    {
        cout << "Square " << index << " has an area of " << squareArray[index].getArea() << endl;
        total += squareArray[index].getArea();
    }

    return total;
}

void resizeSquareNormalParameter(Square square1)
{
    float sideLength = square1.getSideLength();
    square1.setSideLength(sideLength * 2);
}

void resizeSquarePointerParameter(Square * square1)
{
    float sideLength = square1->getSideLength();
    square1->setSideLength(sideLength * 2);
}

void resizeSquareReferenceParameter(Square & square1)
{
    float sideLength = square1.getSideLength();
    square1.setSideLength(sideLength * 2);
}

void resizeSquareArrayNormalParameter(Square * squareArray)
{
    int index;

    cout << "Resizing with Normal Parameters" << endl;

    for(index = 0; index < Square::getCount(); index++)
    {
        resizeSquareNormalParameter(squareArray[index]);
    }
}

void resizeSquareArrayPointerParameter(Square * squareArray)
{
    int index;

    cout << "Resizing with Pointer Parameters" << endl;

    for(index = 0; index < Square::getCount(); index++)
    {
        resizeSquarePointerParameter(&(squareArray[index]));
    }
}

void resizeSquareArrayReferenceParameter(Square * squareArray)
{
    int index;

    cout << "Resizing with Reference Parameters" << endl;

    for(index = 0; index < Square::getCount(); index++)
    {
        resizeSquareReferenceParameter(squareArray[index]);
    }
}

Square createSquare(float newSideLength)
{
    Square newSquare;

    newSquare.setSideLength(newSideLength);

    return newSquare;
}

void replaceSquareArray(Square * squareArray)
{
    int index;

    cout << "Replacing Squares" << endl;

    for(index = 0; index < Square::getCount(); index++)
    {
        squareArray[index] = createSquare(index);
    }
}

int main()
{
    Square * squareArray;
    int numSquares;
    float totalArea;

    cout << "How many Squares to create? ";
    cin >> numSquares;

    squareArray = new Square[numSquares];
    totalArea = calculateTotalArea(squareArray);
    cout << "The Square have a total area of " << totalArea << endl;

    resizeSquareArrayNormalParameter(squareArray);
    totalArea = calculateTotalArea(squareArray);
    cout << "The Square have a total area of " << totalArea << endl;

    resizeSquareArrayPointerParameter(squareArray);
    totalArea = calculateTotalArea(squareArray);
    cout << "The Square have a total area of " << totalArea << endl;

    resizeSquareArrayReferenceParameter(squareArray);
    totalArea = calculateTotalArea(squareArray);
    cout << "The Square have a total area of " << totalArea << endl;

    replaceSquareArray(squareArray);
    totalArea = calculateTotalArea(squareArray);
    cout << "The Square have a total area of " << totalArea << endl;

    delete [] squareArray;
}