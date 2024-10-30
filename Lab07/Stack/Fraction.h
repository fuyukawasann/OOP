// Fraction.h
// This file lists the data and actions for the Fraction class
#pragma once
#include "Number.h"
using namespace std;

class Fraction: public Number
{
public:
    Fraction(int newTop = 0, int newBottom = 1);
    void print() const;
    void setTopAndBottom(int newTop, int newBottom);

    Fraction& setNumerator(int newTop);
    Fraction& setDenominator(int newBottom);

    int getTop() const;
    int getBottom() const;
    void simplify();

    Fraction operator+(Fraction frac2);
    Fraction operator-(Fraction frac2);
    Fraction operator*(Fraction frac2);
    Fraction operator/(Fraction frac2);

    bool operator==(Fraction frac2);
    bool operator>(Fraction frac2);
    bool operator<(Fraction frac2);

private:
    int top, bottom;

};

ostream& operator<<(ostream& output, Fraction& frac1);
int GreatestCommonDenominator(int num1, int num2);