
#include <iostream>
#include "UnitTest.h"
#include "FractionTest.h"
#include "Fraction.h"

using namespace std;

void FractionTest::ConstructorTest()
{
    Fraction frac1, frac2(4), frac3(6, 9);
    UnitTest::assertEquals(frac1.getTop(), 0, "Fraction");
    UnitTest::assertEquals(frac1.getBottom(), 1, "Fraction");
    UnitTest::assertEquals(frac2.getTop(), 4, "Fraction");
    UnitTest::assertEquals(frac2.getBottom(), 1, "Fraction");
    UnitTest::assertEquals(frac3.getTop(), 2, "Fraction");
    UnitTest::assertEquals(frac3.getBottom(), 3, "Fraction");
}

void FractionTest::setTopAndBottomTest()
{
    Fraction frac1, frac2;
    frac1.setTopAndBottom(7, 3);
    UnitTest::assertEquals(frac1.getTop(), 7, "setTopAndBottom");
    UnitTest::assertEquals(frac1.getBottom(), 3, "setTopAndBottom");
    frac2.setTopAndBottom(6, 2);
    UnitTest::assertEquals(frac2.getTop(), 3, "setTopAndBottom");
    UnitTest::assertEquals(frac2.getBottom(), 1, "setTopAndBottom");
}

void FractionTest::getTopTest()
{
    Fraction frac1;
    frac1.setTopAndBottom(8, 3);
    UnitTest::assertEquals(frac1.getTop(), 8, "getTop");
}

void FractionTest::getBottomTest()
{
    Fraction frac1;
    frac1.setTopAndBottom(8, 3);
    UnitTest::assertEquals(frac1.getBottom(), 3, "getBottom");
}

void FractionTest::operatorPlusTest()
{
    Fraction frac1, frac2, frac3;
    frac1.setTopAndBottom(8, 3);
    frac2.setTopAndBottom(5, 7);
    frac3 = frac1 + frac2;
    UnitTest::assertEquals(frac3.getTop(), 71, "operator+");
    UnitTest::assertEquals(frac3.getBottom(), 21, "operator+");
}

void FractionTest::operatorMinusTest()
{
    Fraction frac1, frac2, frac3;
    frac1.setTopAndBottom(8, 3);
    frac2.setTopAndBottom(5, 7);
    frac3 = frac1 - frac2;

    UnitTest::assert(false, "operator-");
}

void FractionTest::operatorTimesTest()
{
    Fraction frac1, frac2, frac3;
    frac1.setTopAndBottom(8, 3);
    frac2.setTopAndBottom(5, 7);
    frac3 = frac1 * frac2;
    UnitTest::assertEquals(frac3.getTop(), 40, "operator*");
    UnitTest::assertEquals(frac3.getBottom(), 21, "operator*");
}

void FractionTest::operatorDivTest()
{
    Fraction frac1, frac2, frac3;
    frac1.setTopAndBottom(8, 3);
    frac2.setTopAndBottom(5, 7);
    frac3 = frac1 / frac2;

    UnitTest::assert(false, "operator/");
}

void FractionTest::operatorEqualTest()
{
    Fraction frac1, frac2;
    frac1.setTopAndBottom(8, 4);
    frac2.setTopAndBottom(6, 3);
    UnitTest::assert(frac1 == frac2, "operator==");
}

void FractionTest::operatorGreaterThanTest()
{
    UnitTest::assert(false, "operator>");
}

void FractionTest::operatorLessThanTest()
{
    UnitTest::assert(false, "operator<");
}

void FractionTest::GreatestCommonDenominatorTest()
{
    int gcd = GreatestCommonDenominator(385, 1045);
    UnitTest::assertEquals(gcd, 55, "GreatestCommonDenominator");
}

int main()
{
    FractionTest::ConstructorTest();
    FractionTest::setTopAndBottomTest();
    FractionTest::getTopTest();
    FractionTest::getBottomTest();
    FractionTest::operatorPlusTest();
    FractionTest::operatorMinusTest();
    FractionTest::operatorTimesTest();
    FractionTest::operatorDivTest();
    FractionTest::operatorEqualTest();
    FractionTest::operatorGreaterThanTest();
    FractionTest::operatorLessThanTest();
    FractionTest::GreatestCommonDenominatorTest();

    UnitTest::printTestResult();
}


