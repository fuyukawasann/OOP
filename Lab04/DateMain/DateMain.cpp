#include <iostream>
#include "Date.h"

using namespace std;

void advanceOneYear(Date& myDate)
{
    myDate.advanceOneYearRef();
}

void advanceOneMonth(Date& myDate)
{
    myDate.advanceOneMonthRef();
}

void advanceOneDay(Date& myDate)
{
    myDate.advanceOneDayRef();
}

int main()
{
    Date d1;

    cout << "Setting the date to 2024/02/17 (Korean Style) using cascading setters" << endl;
    d1.setYear(2024).setMonth(2).setDay(17);
    d1.printDate();

    cout << "Advancing the date one month" << endl;
    advanceOneMonth(d1);
    d1.printDate();

    cout << "Happy St. Patrick's Day!!" << endl << endl;

    cout << "Setting the date to 12/31/2024 (US Style) using cascading setters" << endl;
    d1.setMonth(12).setDay(31).setYear(2024);
    d1.printDate();

    cout << "Advancing the date one day" << endl;
    advanceOneDay(d1);
    d1.printDate();

    cout << "Happy New Year!!" << endl;
}



