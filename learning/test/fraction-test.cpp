// fraction-test.cpp
// test file for class Fraction

#include <fstream>
#include <iostream>
#include "../include/fraction.h"
using namespace std;

int main() {
    Fraction fraction;
    int count = 0;
    string command, inputFile, outputFile;
    
    cout << "Enter name of input file; press return." << endl;
    cin >> inputFile;
    cout << "Enter name of output file; press return" << endl;
    cin >> outputFile;

    ifstream infile(inputFile);
    ofstream outfile(outputFile);

    while (infile >> command)
    {
        if (command == "Quit")
            return 1;
        else if (command == "Initialize")
        {
            int num = 5, denom = 3;
            fraction.Initialize(num, denom);
        }
        else if (command == "GetDenominator")
            outfile << "Denominator: " << fraction.GetDenominator() << endl;
        else if (command == "GetNumerator")
            outfile << "Numerator: " << fraction.GetNumerator() << endl;
        else if (command == "IsZero")
            if (fraction.IsZero())
                outfile << "Fraction is zero" << endl;
            else
                outfile << "Fraction is not zero" << endl;
        else if (command == "IsNotProper")
            if (fraction.IsNotProper())
                outfile << "Fraction is not proper" << endl;
            else
                outfile << "Fraction is proper" << endl;
        else
        {
            outfile << "Whole number is " << fraction.ConvertToProper() << endl;
            outfile << "Denominator: " << fraction.GetDenominator() << endl;
            outfile << "Numerator: " << fraction.GetNumerator() << endl;
        }

        count++;
        cout << "Command number " << count << " completed." << endl;
    }

    return 0;
}