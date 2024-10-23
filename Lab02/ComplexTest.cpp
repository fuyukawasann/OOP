#include <iostream>
#include "ComplexTest.h"
#include "Complex.h"
#include "UnitTest.h"

using namespace std;

void ComplexTest::ConstructorTest()
{
    Complex complex1, complex2(3), complex3(4, 5);

    UnitTest::assertEquals(complex1.getReal(), 0.0, "Complex");
    UnitTest::assertEquals(complex1.getImaginary(), 0.0, "Complex");
    UnitTest::assertEquals(complex2.getReal(), 3.0, "Complex");
    UnitTest::assertEquals(complex2.getImaginary(), 0.0, "Complex");
    UnitTest::assertEquals(complex3.getReal(), 4.0, "Complex");
    UnitTest::assertEquals(complex3.getImaginary(), 5.0, "Complex");
}

void ComplexTest::setRealAndImaginaryTest()
{
    Complex complex1;
    complex1.setRealAndImaginary(3, 8);
    UnitTest::assertEquals(complex1.getReal(), 3.0, "setRealAndImaginary");
    UnitTest::assertEquals(complex1.getImaginary(), 8.0, "setRealAndImaginary");
}

void ComplexTest::getRealTest()
{
    Complex complex1;
    complex1.setRealAndImaginary(5, 9);
    UnitTest::assertEquals(complex1.getReal(), 5.0, "getRealAndImaginary");
}

void ComplexTest::getImaginaryTest()
{
    Complex complex1;
    complex1.setRealAndImaginary(5, 9);
    UnitTest::assertEquals(complex1.getImaginary(), 9.0, "getImaginary");
}

void ComplexTest::operatorPlusTest()
{
    Complex complex1(1, 2), complex2(3, 4), complex3;
    complex3 = complex1 + complex2;
    UnitTest::assertEquals(complex3.getReal(), 4.0, "operator+");
    UnitTest::assertEquals(complex3.getImaginary(), 6.0, "operator+");
}

void ComplexTest::operatorMinusTest()
{
    Complex complex1(5, 7), complex2(3, 4), complex3;
    complex3 = complex1 - complex2;
    UnitTest::assertEquals(complex3.getReal(), 2.0, "operator-");
    UnitTest::assertEquals(complex3.getImaginary(), 3.0, "operator-");
}


void ComplexTest::operatorTimesTest()
{
    Complex complex1(7, 3), complex2(3, 4), complex3;
    complex3 = complex1 * complex2;
    UnitTest::assertEquals(complex3.getReal(), 9.0, "operator*");
    UnitTest::assertEquals(complex3.getImaginary(), 37.0, "operator*");
}

void ComplexTest::operatorDivTest()
{
    Complex complex1(7, 6), complex2(5, 4), complex3;
    complex3 = complex1 / complex2;
    UnitTest::assertEquals(complex3.getReal(), 59.0/41.0, "operator/");
    UnitTest::assertEquals(complex3.getImaginary(), 2.0/41.0, "operator/");
}

void ComplexTest::operatorEqualsTest()
{
    Complex complex1(1, 2), complex2(3, 4), complex3(1, 2);
    UnitTest::assert(complex1 == complex3, "operator==");
    UnitTest::assert(!(complex1 == complex2), "operator==");
}

int main()
{
    ComplexTest::ConstructorTest();
    ComplexTest::setRealAndImaginaryTest();
    ComplexTest::getRealTest();
    ComplexTest::getImaginaryTest();
    ComplexTest::operatorPlusTest();
    ComplexTest::operatorMinusTest();
    ComplexTest::operatorTimesTest();
    ComplexTest::operatorDivTest();
    ComplexTest::operatorEqualsTest();

    UnitTest::printTestResult();
}