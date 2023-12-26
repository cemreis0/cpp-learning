// DateType Implementation File

#include "DateType.h"
#include <fstream>
#include <iostream>

using namespace std;

// number of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// names of the months
static string conversionTable[] = {"Error", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void DateType::initialize(int newDay, int newMonth, int newYear)
// post:    an exception is thrown if newMonth is not between 1 and 12,
//          if newDay is not consistent with newMonth, or if newYear
//          is before 1583; otherwise, a date is initialized
{
    if (newMonth < 1 || newMonth > 12)
        throw string("month is invalid");
    else if (newDay < 1 || newDay > daysInMonth[newMonth])
        throw string("day is invalid");
    else if (newYear < 1583)
        throw string("year is invalid");
    
    year = newYear;
    month = newMonth;
    day = newDay;
}

int DateType::getDay() const
{
    return day;
}

int DateType::getMonth() const
{
    return month;
}

int DateType::getYear() const
{
    return year;
}

DateType DateType::adjust(int daysAway) const
{
    int newDay = day + daysAway;
    int newMonth = month;
    int newYear = year;
    bool finished = false;
    int daysInThisMonth;
    DateType returnDate;

    while (!finished)
    {
        daysInThisMonth = daysInMonth[newMonth];
        if (newMonth == 2)
            if (((newYear % 4 == 0) && !(newYear % 100 == 0)) || (newYear % 400 == 0))
                daysInThisMonth++;
        if (newDay <= daysInThisMonth)
            finished = true;
        else
        {
            newDay = newDay - daysInThisMonth;
            newMonth = (newMonth % 12) + 1;
            if (newMonth == 1)
                newYear++;
        }
    }

    returnDate.initialize(newDay, newMonth, newYear);

    return returnDate;
}

RelationType DateType::compareTo(DateType otherDate) const
{
    if (year < otherDate.year)
        return LESS;
    else if (year > otherDate.year)
        return GREATER;
    else if (month < otherDate.month)
        return LESS;
    else if (month > otherDate.month)
        return GREATER;
    else if (day < otherDate.day)
        return LESS;
    else if (day > otherDate.day)
        return GREATER;
    else
        return EQUAL;
}