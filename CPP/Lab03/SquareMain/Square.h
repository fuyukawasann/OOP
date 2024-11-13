// Square.h
// This class describes a Square

class Square
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

    void setCenter(float newX, float newY);
    void setSideLength(float newSideLength);
    float getX() const;
    float getY() const;
    float getSideLength() const;
    float getArea() const;
    static int getCount();
};