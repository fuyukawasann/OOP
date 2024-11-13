//
// Created by 이한별 on 24. 10. 2.
//

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

// Constructor
Date::Date()
{
    setYear(2024);
    setMonth(1);
    setDay(1);
}

void Date::setYearVal(int newYear)
{
    year = newYear;
}

void Date::setMonthVal(int newMonth)
{
    // month가 1 미만 12 초과면 에러
    if(newMonth < 1 || newMonth > 12)
    {
        cout << "Error setting Month" << endl;
    }
    else month = newMonth;
}

void Date::setDayVal(int newDay)
{
    if(newDay < 1 || newDay > 31)
        cout << "Error setting Day" << endl;
    else day = newDay;
}

Date& Date::setYear(int newYear)
{
    setYearVal(newYear);
    return *this;
}

Date& Date::setMonth(int newMonth)
{
    setMonthVal(newMonth);
    return *this;
}

Date& Date::setDay(int newDay)
{
    setDayVal(newDay);
    return *this;
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

void Date::advanceOneYearRef()
{
    setYear(year + 1);
}

void Date::advanceOneMonthRef()
{
    int newMonth = month + 1;
    if(newMonth > 12)
    {
        newMonth = 0;
        advanceOneYearRef();
    }
    month = newMonth;
}

void Date::advanceOneDayRef()
{
    int newDay = day + 1;
    if(newDay > 31)
    {
        newDay = 0;
        advanceOneMonthRef();
    }

    day = newDay;
}





// print
void Date::printTwoDigits(int number) const
{
    cout << setw(2) << setfill('0') << number;
}

void Date::printDate() const
{
    cout << getYear() << "/";
    printTwoDigits(getMonth());
    cout << "/";
    printTwoDigits(getDay());
    cout << endl;
}

