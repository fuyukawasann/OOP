//
// Created by 이한별 on 24. 9. 11.
//
#include <iostream>
#include "Complex.h"
#include "Number.h"

using namespace std;

Complex::Complex(float newReal, float newImag)
{
    setRealAndImaginary(newReal, newImag);
}

void Complex::setRealAndImaginary(float newReal, float newImag)
{
    real = newReal;
    imaginary = newImag;
}

Complex& Complex::setReal(float newReal)
{
    real = newReal;

    return *this;
}

Complex& Complex::setImaginary(float newImaginary)
{
    imaginary = newImaginary;

    return *this;
}


void Complex::print() const
{
    cout << real << " + " << imaginary << "i" << endl;
}

float Complex::getReal()
{
    return real;
}

float Complex::getImaginary()
{
    return imaginary;
}

Complex Complex::operator+(Complex complex2)
{
    Complex newComplex;
    float newReal = real + complex2.getReal();
    float newImag = imaginary + complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

Complex Complex::operator-(Complex complex2)
{
    Complex newComplex;
    float newReal = real - complex2.getReal();
    float newImag = imaginary - complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

Complex Complex::operator*(Complex complex2)
{
    Complex newComplex;
    float newReal = real * complex2.getReal() - imaginary * complex2.getImaginary();
    float newImag = imaginary * complex2.getReal() + real * complex2.getImaginary();
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

Complex Complex::operator/(Complex complex2)
{
    Complex newComplex;
    float newReal = (real * complex2.getReal() + imaginary * complex2.getImaginary()) /
        (complex2.getReal() * complex2.getReal() + complex2.getImaginary() * complex2.getImaginary());
    float newImag = (imaginary * complex2.getReal() - real * complex2.getImaginary()) /
        (complex2.getReal() * complex2.getReal() + complex2.getImaginary() * complex2.getImaginary());
    newComplex.setRealAndImaginary(newReal, newImag);

    return newComplex;
}

bool Complex::operator==(Complex complex2)
{
    return real == complex2.getReal() && imaginary == complex2.getImaginary();
}

ostream& operator<<(ostream& output, Complex& complex1)
{
    output << complex1.getReal() << " + " << complex1.getImaginary() << "i";
    return output;
}

