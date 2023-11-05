// src/template.cpp

#include <iostream>
#include "../include/template.h"
using namespace std;

int main()
{
    int ai = 12;
    int bi = 15;
    int mi1 = minimum<int>(ai, bi);
    cout << mi1 << endl;
    int mi2 = minimum(ai, bi);
    cout << mi2 << endl;


    char ac = 'a';
    char bc = 'b';
    char mc1 = minimum<char>(ac, bc);
    cout << mc1 << endl;
    char mc2 = minimum(ac, bc);
    cout << mc2 << endl;

    string as = "ba";
    string bs = "bb";
    string ms1 = minimum<string>(as, bs);
    cout << ms1 << endl;
    string ms2 = minimum(as, bs);
    cout << ms2 << endl;

    

    return 0;
}