// Fraction.h
// This file lists the data and actions for the Fraction class

#include <ostream>
using namespace std;

class Fraction
{
public:
    Fraction(); // Default Fraction is 0 / 1
    Fraction(int newTop);
    Fraction(int newTop, int newBottom);
    void print();
    void setTopAndBottom(int newTop, int newBottom);
    int getTop();
    int getBottom();
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