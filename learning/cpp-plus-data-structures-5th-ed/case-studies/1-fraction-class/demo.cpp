// FractionType Demo File

#include "FractionType.h"
#include <iostream>

int main()
{
    using namespace std;

    FractionType frac1, frac2, frac3;

    frac1.initialize(15, 5);
    frac2.initialize(7, 12);
    frac3.initialize(0, 10);

    cout << "getNumerator()" << endl;
    cout << frac1.getNumerator() << endl;
    cout << frac2.getNumerator() << endl;
    cout << frac3.getNumerator() << endl;

    cout << "getDenominator()" << endl;
    cout << frac1.getDenominator() << endl;
    cout << frac2.getDenominator() << endl;
    cout << frac3.getDenominator() << endl;

    cout << "isZero()" << endl;
    cout << frac1.isZero() << endl;
    cout << frac2.isZero() << endl;
    cout << frac3.isZero() << endl;

    cout << "isProper()" << endl;
    cout << frac1.isProper() << endl;
    cout << frac2.isProper() << endl;
    cout << frac3.isProper() << endl;

    cout << "Attempting convertToProper()" << endl;
    frac1.convertToProper();
    frac1.convertToProper();
    frac3.convertToProper();

    cout << "isProper()" << endl;
    cout << frac1.isProper() << endl;
    cout << frac2.isProper() << endl;
    cout << frac3.isProper() << endl;

    return 0;
}
