// Date.h

class Date
{
private:
    int year, month, day;

public:
    // Constructor
    Date();

    // Setter
    void setYearVal(int newYear);
    void setMonthVal(int newMonth);
    void setDayVal(int newDay);

    Date& setYear(int newYear);
    Date& setMonth(int newMonth);
    Date& setDay(int newDay);

    // Getter
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    // Advance year, month and a day
    void advanceOneDayRef();
    void advanceOneMonthRef();
    void advanceOneYearRef();

    // print
    void printTwoDigits(int number) const;
    void printDate() const;
};