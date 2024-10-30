//
// Created by 이한별 on 24. 9. 11.
//
#include <iostream>
#include "ComplexFraction.h"
#include "Number.h"

using namespace std;

ComplexFraction::ComplexFraction(Fraction newReal, Fraction newImag)
{
    setRealAndImaginary(newReal, newImag);
}

void ComplexFraction::setRealAndImaginary(Fraction newReal, Fraction newImag)
{
    real = newReal;
    imaginary = newImag;
}

ComplexFraction& ComplexFraction::setReal(Fraction newReal)
{
    real = newReal;

    return *this;
}

ComplexFraction& ComplexFraction::setImaginary(Fraction newImaginary)
{
    imaginary = newImaginary;

    return *this;
}


void ComplexFraction::print() const
{
    real.print();
    if(imaginary.getTop() != 0)
    {
        cout << "+";
        imaginary.print();
        cout << "i";
    }
}

Fraction ComplexFraction::getReal() const
{
    return real;
}

Fraction ComplexFraction::getImaginary() const
{
    return imaginary;
}

ComplexFraction ComplexFraction::operator+(ComplexFraction complex2)
{
    ComplexFraction newComplex;
    Fraction newReal = real + complex2.getReal();
    Fraction newImag = imaginary + complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

ComplexFraction ComplexFraction::operator-(ComplexFraction complex2)
{
    ComplexFraction newComplex;
    Fraction newReal = real - complex2.getReal();
    Fraction newImag = imaginary - complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

ComplexFraction ComplexFraction::operator*(ComplexFraction complex2)
{
    ComplexFraction newComplex;
    Fraction newReal = real * complex2.getReal() - imaginary * complex2.getImaginary();
    Fraction newImag = imaginary * complex2.getReal() + real * complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

ComplexFraction ComplexFraction::operator/(ComplexFraction complex2)
{
    ComplexFraction newComplex;
    Fraction newReal = (real * complex2.getReal() + imaginary * complex2.getImaginary()) /
        (complex2.getReal() * complex2.getReal() + complex2.getImaginary() * complex2.getImaginary());
    Fraction newImag = (imaginary * complex2.getReal() - real * complex2.getImaginary()) /
        (complex2.getReal() * complex2.getReal() + complex2.getImaginary() * complex2.getImaginary());
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

bool ComplexFraction::operator==(ComplexFraction complex2)
{
    return real == complex2.getReal() && imaginary == complex2.getImaginary();
}

// ostream& operator<<(ostream& output, ComplexFraction& complex1)
// {
//     output << complex1.getReal() << " + " << complex1.getImaginary() << "i";
//     return output;
// }

