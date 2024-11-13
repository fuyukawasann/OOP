// Clock.h
// This file lists data and actions for the Fraction class


class Clock {
public:
    Clock();
    void setHour(int newHour);
    void setMinute(int newMinute);
    void setSecond(int newSecond);
    int getHour();
    int getMinute();
    int getSecond();
    void print();

private:
    int hour, minute, second;
};

