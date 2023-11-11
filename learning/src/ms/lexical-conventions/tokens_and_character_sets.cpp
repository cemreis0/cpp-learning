// src/ms/lexical-conventions/tokens_and_character_sets.cpp

#include <iostream>
using namespace std;

int main()
{
    // The text of a C++ program consists of tokens and white space. 
    // A token is the smallest element of a C++ program that is meaningful to the compiler.

    // The Microsoft C++ compiler treats a character in universal character name form and literal form interchangeably. 
    // For example, you can declare an identifier using universal character name form, and use it in literal form:
    auto \u30AD = 42;
    if (キ == 42) cout << "true" << endl;

    return 0;
}