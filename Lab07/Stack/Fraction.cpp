//
// Created by 이한별 on 24. 9. 11.
//

#include <iostream>
#include "Fraction.h"
#include "Number.h"

using namespace std;

Fraction::Fraction(int newTop, int newBottom)
{
    setTopAndBottom(newTop, newBottom);
}

void Fraction::print() const
{
    if(bottom == 1) cout << top;
    else cout << "(" << top << "/" << bottom << ")";
}

void Fraction::setTopAndBottom(int newTop, int newBottom)
{
    if(newBottom == 0)
    {
        cout << "Error creating a fraction with a zero denominator" << endl;
    }
    top = newTop;
    bottom = newBottom;
    simplify();
}

Fraction& Fraction::setNumerator(int newTop)
{
    top = newTop;

    return *this;
}

Fraction& Fraction::setDenominator(int newBottom)
{
    bottom = newBottom;

    return *this;
}


int Fraction::getTop() const
{
    return top;
}

int Fraction::getBottom() const
{
    return bottom;
}

void Fraction::simplify()
{
    int gcd = GreatestCommonDenominator(getTop(), getBottom());

    top /= gcd;
    bottom /= gcd;
}

Fraction Fraction::operator+(Fraction frac2)
{
    Fraction newFraction;
    int newBottom = bottom * frac2.getBottom();
    int newTop = top * frac2.getBottom() + bottom * frac2.getTop();
    newFraction.setTopAndBottom(newTop, newBottom);

    return newFraction;
}

Fraction Fraction::operator-(Fraction frac2)
{
    Fraction newFraction;
    int newBottom = bottom * frac2.getBottom();
    int newTop = top * frac2.getBottom() - bottom * frac2.getTop();
    newFraction.setTopAndBottom(newTop, newBottom);

    return newFraction;
}

Fraction Fraction::operator*(Fraction frac2)
{
    Fraction newFraction;
    int newBottom = bottom * frac2.getBottom();
    int newTop = top * frac2.getTop();
    newFraction.setTopAndBottom(newTop, newBottom);

    return newFraction;
}

Fraction Fraction::operator/(Fraction frac2)
{
    Fraction newFraction;
    int newBottom = bottom * frac2.getTop();
    int newTop = top * frac2.getBottom();
    newFraction.setTopAndBottom(newTop, newBottom);

    return newFraction;
}

bool Fraction::operator==(Fraction frac2)
{
    return (top * frac2.getBottom() == bottom * frac2.getTop());
}

bool Fraction::operator<(Fraction frac2)
{
    return (top * frac2.getBottom() < bottom * frac2.getTop());
}

bool Fraction::operator>(Fraction frac2)
{
    return (top * frac2.getBottom() > bottom * frac2.getTop());
}

ostream& operator<<(ostream& output, Fraction& frac)
{
    output << frac.getTop() << "/" << frac.getBottom();
    return output;
}

int GreatestCommonDenominator(int num1, int num2)
{
    if(num1 == 0) return num2;
    if(num1 < 0) return GreatestCommonDenominator(-num1, num2);
    if(num1 > num2) return GreatestCommonDenominator(num2, num1);
    return GreatestCommonDenominator(num2 - num1, num1);
}