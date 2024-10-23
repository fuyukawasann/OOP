//
// Created by 이한별 on 24. 10. 16.
//


#include <iostream>
#include "Number.h"
#include "Fraction.h"
#include "Complex.h"

using namespace std;

Complex* makeComplex()
{
    Complex* complex1 = new Complex;

    float real, imag;

    cout << "What is the Real Part? ";
    cin >> real;
    cout << "What is the Imaginary Part? ";
    cin >> imag;
    complex1->setReal(real).setImaginary(imag);
    return complex1;
}

Fraction* makeFraction()
{
    Fraction* frac1 = new Fraction;
    int numer, denom;

    cout << "What is the Numerator? ";
    cin >> numer;
    cout << "What is the Denominator? ";
    cin >> denom;
    frac1->setNumerator(numer).setDenominator(denom).simplify();
    return frac1;
}

int main()
{
    Number* num1;

    int numberType;

    cout << "1) Complex or 2) Fraction ";
    cin >> numberType;

    switch(numberType)
    {
        case 1: num1 = makeComplex(); break;
        case 2: num1 = makeFraction(); break;
        default: cout << "Error: Invalid Number Class" << endl; return 1;
    }

    num1->print();
    cout << endl;

    return 0;
}