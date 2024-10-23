

#include <ostream>

#include "Number.h"
using namespace std;

class Complex: public Number
{
public:
    Complex(float newReal = 0.0, float newImag = 0.0);

    void print() const;
    void setRealAndImaginary(float newReal, float newImaginary);

    Complex& setReal(float newReal);
    Complex& setImaginary(float newImaginary);

    float getReal();
    float getImaginary();
    Complex operator+(Complex complex2);
    Complex operator-(Complex complex2);
    Complex operator*(Complex complex2);
    Complex operator/(Complex complex2);
    bool operator==(Complex complex2);
private:
    float real, imaginary;
};

ostream& operator<< (ostream& output, Complex& complex1);