#include <iostream>
#include <iomanip>
#include "Clock.h"

using namespace std;

// Constructor
Clock::Clock()
{
    setHour(12);
    setMinute(0);
    setSecond(0);
}

// Setter
void Clock::setHour(int newHour)
{
    if (newHour < 0)
    {
        cout << "Error: Hour too small" << endl;
    }
    else if(newHour > 23)
    {
        cout << "Error: Hour too big" << endl;
    }
    else hour = newHour;
}

void Clock::setMinute(int newMinute)
{
    if(newMinute < 0)
    {
        cout << "Error: Minute too small" << endl;
    }
    else if(newMinute > 59)
    {
        cout << "Error: Minute too big" << endl;
    }
    else minute = newMinute;
}

void Clock::setSecond(int newSecond)
{
    if(newSecond < 0)
    {
        cout << "Error: Second too small" << endl;
    }
    else if(newSecond > 59)
    {
        cout << "Error: Second too big" << endl;
    }
    else second = newSecond;
}



// Getter
int Clock::getHour()
{
    return hour;
}

int Clock::getMinute()
{
    return minute;
}

int Clock::getSecond()
{
    return second;
}

// Print
void Clock::print()
{
    cout << getHour() << ":"
    << setw(2) << setfill('0') << getMinute() << ":"
    << setw(2) << setfill('0') << getSecond() << endl;
}