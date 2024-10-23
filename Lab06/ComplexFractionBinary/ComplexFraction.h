

#include <iostream>
#include "Fraction.h"
#include "Number.h"
using namespace std;

class ComplexFraction: public Number
{
public:
    ComplexFraction(Fraction newReal = Fraction(), Fraction newImag = Fraction());

    void print() const;
    void setRealAndImaginary(Fraction newReal, Fraction newImaginary);

    ComplexFraction& setReal(Fraction newReal);
    ComplexFraction& setImaginary(Fraction newImaginary);

    Fraction getReal() const;
    Fraction getImaginary() const;
    ComplexFraction operator+(ComplexFraction complex2);
    ComplexFraction operator-(ComplexFraction complex2);
    ComplexFraction operator*(ComplexFraction complex2);
    ComplexFraction operator/(ComplexFraction complex2);
    bool operator==(ComplexFraction complex2);
private:
    Fraction real, imaginary;
};

// ostream& operator<< (ostream& output, ComplexFraction& complex1);