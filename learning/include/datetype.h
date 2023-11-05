// include/datetype.h

#include <string>
using namespace std;

class DateType
{
    public:
        void Initialize(int newDay, int newMonth, int newYear);
        int GetMonth() const;
        string GetMonthAsString() const;
        int GetDay() const;
        int GetYear() const;
        int CompareTo(DateType aDate) const;
        DateType Adjust(int daysAway) const;
    private:
        bool IsLeapYear(int aYear) const;
        static const string conversionTable[13];
        int day, month, year;
};