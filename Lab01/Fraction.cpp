#include <iostream>
#include "Fraction.h"

using namespace std;

// Const
Fraction::Fraction()
{
    // setTop as 1 to prevent "A Zero Denominator" at Inverted
    setTop(1);
    setDenominator(1);
}

// Setter
void Fraction::setTop(int newTop)
{
    if(newTop == 0)
        cout << "Warning: Inverted has a zero denominator" << endl;
    top = newTop;
}

void Fraction::setDenominator(int newDenominator)
{
    if(newDenominator == 0)
        cout << "Warning: Fraction has a zero denominator" << endl;
    denominator = newDenominator;
}

// Getter
int Fraction::getTop()
{
    return top;
}

int Fraction::getDenominator()
{
    return denominator;
}

void Fraction::print()
{
    cout << getTop() << " / " << getDenominator() << endl;
}

void Fraction::printInverted()
{
    cout << getDenominator() << " / " << getTop() << endl;
}

void Fraction::printDoubled()
{
    cout << getTop() * 2 << " / " << getDenominator() << endl;
}

void Fraction::printSquared()
{
    cout << getTop() * getTop() << " / " << getDenominator() * getDenominator() << endl;
}

void Fraction::printFloatingPoint()
{
    cout << (float) getTop() / (float)getDenominator() << endl;
}
