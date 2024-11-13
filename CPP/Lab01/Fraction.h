class Fraction
{
public:
    Fraction();
    void setTop(int newTop);
    void setDenominator(int newDenominator);
    int getTop();
    int getDenominator();
    void print();
    void printInverted();
    void printDoubled();
    void printSquared();
    void printFloatingPoint();

private:
    int top, denominator;
};