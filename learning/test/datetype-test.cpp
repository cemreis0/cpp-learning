// test.datetype-test.cpp

#include <iostream>
#include <vector>
#include <fstream>
#include "../src/datetype.cpp"
#include <cstring>
using namespace std;

vector<int> extractDateType(string str);

int main()
{
    string command;

    ifstream infile("../test-files/datetype-test-in.txt");
    ifstream infileValuesAdjust("../test-files/datetype-test-values-adjust.txt");
    ifstream infileValuesCompareTo("../test-files/datetype-test-values-compareto.txt");
    ifstream infileValuesInitialize("../test-files/datetype-test-values-initialize.txt");
    ofstream outfile("../test-files/datetype-test-out.txt");

    while (infile >> command)
    {
        if (command == "Quit")
            return 1;
        else if (command == "Initialize")
        {
            outfile << "command: " << command << endl;
            string str; // value read from input file
            // read value file line by line
            while (getline(infileValuesInitialize, str))
            {
                DateType date;
                try
                {
                    vector<int> dates = extractDateType(str);
                    date.Initialize(dates[0], dates[1], dates[2]);
                    outfile << "date successfully created" << endl;
                }
                catch(const exception& e)
                {
                    outfile << "error: " << e.what() << endl;
                }
                catch(const string& e)
                {
                    outfile << "error: " << e << endl;
                }
            }
            outfile << "\n" << endl;
        }
        else if (command == "GetMonth")
        {
            outfile << "command: " << command << endl;
            DateType date;
            int month;
            try
            {
                date.Initialize(1, 1, 2000);
                month = date.GetMonth();
                outfile << "month: " << month << endl;
            }
            catch(const exception& e)
            {
                outfile << "error: " << e.what() << endl;
            }
            outfile << "\n" << endl;
        }
        else if (command == "GetMonthAsString")
        {
            outfile << "command: " << command << endl;
            DateType date1, date2;
            string month1, month2;
            try
            {  
                date1.Initialize(10, 1, 2010);
                month1 = date1.GetMonthAsString();
                outfile << "month as string: " << month1 << endl;
                date2.Initialize(10, 12, 2010);
                month2 = date2.GetMonthAsString();
                outfile << "month as string: " << month2 << endl;
            }
            catch(const exception& e)
            {
                outfile << "error: " << e.what() << endl;
            }
            outfile << "\n" << endl;
        }
        else if (command == "GetDay")
        {
            outfile << "command: " << command << endl;
            DateType date1, date2;
            int day1, day2;
            try
            {
                date1.Initialize(29, 2, 2008);
                day1 = date1.GetDay();
                outfile << "day: " << day1 << endl;
                date2.Initialize(31, 1, 2000);
                day2 = date2.GetDay();
                outfile << "day: " << day2 << endl;
            }
            catch(const exception& e)
            {
                outfile << "error: " << e.what() << endl;
            }
            outfile << "\n" << endl;
        }
        else if (command == "GetYear")
        {
            outfile << "command: " << command << endl;
            DateType date1, date2;
            int year1, year2;
            try
            {
                date1.Initialize(1, 1, 1583);
                year1 = date1.GetYear();
                outfile << "year: " << year1 << endl;
                date2.Initialize(1, 1, 2100);
                year2 = date2.GetYear();
                outfile << "year: " << year2 << endl;
            }
            catch(const exception& e)
            {
                outfile << "error: " << e.what() << endl;
            }
            outfile << "\n" << endl;
        }
        else if (command == "CompareTo")
        {
            outfile << "command: " << command << endl;
            string str; // value read from input file
            // read the file line by line
            while (getline(infileValuesCompareTo, str))
            {
                DateType date1, date2;
                int comparison;
                try
                {
                    vector<int> dates1 = extractDateType(str);
                    str = str.substr(str.find("&")+1);
                    vector<int> dates2 = extractDateType(str);

                    date1.Initialize(dates1[0], dates1[1], dates1[2]);
                    date2.Initialize(dates2[0], dates2[1], dates2[2]);

                    comparison = date1.CompareTo(date2);

                    outfile << "comparison result: "<< comparison << endl;
                }
                catch(const exception& e)
                {
                    outfile << "error: " << e.what() << endl;
                }
            }
            outfile << "\n" << endl;
        }
        else if (command == "Adjust")
        {
            outfile << "command: " << command << endl;
            string str; // value read from input file
            // read the file line by line
            while (getline(infileValuesAdjust, str))
            {
                DateType date, adjustedDate;
                int days;
                try
                {
                    vector<int> dates = extractDateType(str);
                    str = str.substr(str.find("&")+1);
                    days = stoi(str);

                    date.Initialize(dates[0], dates[1], dates[2]);

                    adjustedDate = date.Adjust(days);

                    outfile << "adjusted date: " << adjustedDate.GetDay() << " " << adjustedDate.GetMonth() << " " << adjustedDate.GetYear() << endl;
                }
                catch(const exception& e)
                {
                    outfile << "error: " << e.what() << endl;
                }
                catch(const string& e)
                {
                    outfile << "error: " << e << endl;
                }
            }
            outfile << "\n" << endl;
        }
    }

    return 0;
}

vector<int> extractDateType(string str)
{
    vector<int> dates;
    int day, month, year;
    int firstSpacePos, secondSpacePos;
    string splitValue;

    firstSpacePos = str.find(" ");
    secondSpacePos = str.find(" ", firstSpacePos + 1);

    splitValue = str.substr(0, firstSpacePos);
    day = stoi(splitValue);
    dates.push_back(day);

    splitValue = str.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
    month = stoi(splitValue);
    dates.push_back(month);

    splitValue = str.substr(secondSpacePos + 1);
    year = stoi(splitValue);
    dates.push_back(year);

    return dates;
}