//
// Created by 이한별 on 24. 10. 16.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle: public Shape {
private:
    float height, width, bottom, left;

public:
    Triangle& setHeight(float newHeight);
    Triangle& setWidth(float newWidth);
    Triangle& setBottom(float newBottom);
    Triangle& setLeft(float newLeft);
    void setColor(int newColor) override;

    float getHeight() const;
    float getWidth() const;
    float getBottom() const;
    float getLeft() const;

    float getArea() const;

};



#endif //TRIANGLE_H
