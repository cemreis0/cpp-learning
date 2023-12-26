// DateType Header File

#pragma once

#include <string>
#include <fstream>

using namespace std;

enum RelationType {LESS, EQUAL, GREATER};

class DateType
{
    public:
        void initialize(int newDay, int newMonth, int newYear);
        // post:    if all parameters represent a valid date,
        //          self is initialized to the parameters; otherwise
        //          a string exception is thrown, stating the first
        //          incorrect parameter

        int getDay() const;
        // function: return day

        int getMonth() const;
        // function: return month

        int getYear() const;
        // function: return year

        string getMonthString() const;
        // function: return month as a string

        DateType adjust(int daysAway) const;
        // function: return a date daysAway from self

        RelationType compareTo(DateType otherDate) const;
        // function: returns a RelationType LESS, EQUAL, GREATER compared to self

    private:
        int year, month, day;
};