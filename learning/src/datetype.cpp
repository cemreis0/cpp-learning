// src/datetype.cpp

#include "../include/datetype.h"

const string DateType::conversionTable[] = {"Error", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void DateType::Initialize(int newDay, int newMonth, int newYear)
{
    if (newDay < 1 || newDay > daysInMonth[newMonth])
        if (IsLeapYear(newYear) && newMonth == 2)
            if (newDay > (daysInMonth[newMonth] + 1))
                throw string("day is invalid (" + to_string(newDay) + ")");
        else
            throw string("day is invalid (" + to_string(newDay) + ")");
    if (newMonth < 1 || newMonth > 12)
        throw string("month is invalid (" + to_string(newMonth) + ")");
    if (newYear < 1583) // start of gregorian calendar
        throw string("year is invalid (" + to_string(newYear) + ")");

    day = newDay;
    month = newMonth;
    year = newYear;
}

int DateType::GetDay() const
{
    return day;
}

int DateType::GetMonth() const
{
    return month;
}

string DateType::GetMonthAsString() const
{
    return conversionTable[month];
}

int DateType::GetYear() const
{
    return year;
}

// 1 - aDate is greater, 0 - equal, -1 - aDate is less
int DateType::CompareTo(DateType aDate) const
{
    if (year < aDate.year)
        return 1;
    else if (year > aDate.year)
        return -1;
    else if (month < aDate.month)
        return 1;
    else if (month < aDate.month)
        return -1;
    else if (day < aDate.day)
        return 1;
    else if (day > aDate.day)
        return -1;
    else return 0;
}

bool DateType::IsLeapYear(int aYear) const
{
    bool leapYear = true;

    if (aYear % 4 != 0 || aYear % 100 == 0 || aYear != 400)
        leapYear = false;

    return leapYear;
}

DateType DateType::Adjust(int daysAway) const
{
    int newDay = day + daysAway;
    int newMonth = month;
    int newYear = year;
    bool finished = false;
    int daysInThisMonth;
    DateType adjustedDate;

    while (!finished)
    {
        daysInThisMonth = daysInMonth[newMonth];
        if (newMonth == 2 && IsLeapYear(newYear))
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

    adjustedDate.Initialize(newDay, newMonth, newYear);
    return adjustedDate;
}
