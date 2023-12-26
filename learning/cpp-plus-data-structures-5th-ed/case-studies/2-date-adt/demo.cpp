// DateType Demo File

#include "DateType.h"
#include <iostream>

int main()
{
    using namespace std;

    DateType date1, date2, date3;

    try
    {
        date1.initialize(30, 12, 2022);
        date2.initialize(1, 1, 2023);

        cout << "Date 1: " << date1.getDay() << "/" << date1.getMonth() << "/" << date1.getYear() << endl;
        cout << "Date 2: " << date2.getDay() << "/" << date2.getMonth() << "/" << date2.getYear() << endl;

        cout << "Comparison between Date 1 and Date 2: ";
        switch (date1.compareTo(date2)) {
            case LESS:
                cout << "Date 1 is earlier than Date 2" << endl;
                break;
            case GREATER:
                cout << "Date 1 is later than Date 2" << endl;
                break;
            case EQUAL:
                cout << "Date 1 is equal to Date 2" << endl;
                break;
        }
        
        cout << "Adjusting Date 1 by 5 days: ";
        DateType adjustedDate = date1.adjust(5);
        cout << adjustedDate.getDay() << "/" << adjustedDate.getMonth() << "/" << adjustedDate.getYear() << endl;

    }
    catch (const string& errorMessage)
    {
        cerr << "Error: " << errorMessage << endl;
    }

    return 0;
}