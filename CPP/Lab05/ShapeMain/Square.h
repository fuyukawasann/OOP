// Square.h
// This class describes a Square


#include "Shape.h"

class Square : public Shape
{
private:
    float centerX;
    float centerY;
    float sideLength;
    static int count;

public:
    Square();
    Square(const Square & copyFrom);
    ~Square();
    Square & operator=(const Square & copyFrom);

    Square& setCenter(float newX, float newY);
    Square& setSideLength(float newSideLength);
    Square& setX(float newX);
    Square& setY(float newY);
    float getX() const;
    float getY() const;
    float getSideLength() const;
    float getArea() const;
    static int getCount();
};
