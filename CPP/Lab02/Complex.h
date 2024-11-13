

#include <ostream>
using namespace std;

class Complex
{
public:
    Complex(float newReal = 0.0, float newImag = 0.0);

    void print();
    void setRealAndImaginary(float newReal, float newImaginary);
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