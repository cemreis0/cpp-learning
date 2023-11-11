// src/ms/lexical-conventions/identifiers.cpp

#include <iostream>
using namespace std;

int main()
{
    // The first character of an identifier must be an alphabetic character, 
    // either uppercase or lowercase, or an underscore ( _ ). 
    // Because C++ identifiers are case sensitive, fileName is different from FileName.

    // Identifiers cannot be exactly the same spelling and case as keywords. 
    // Identifiers that contain keywords are legal. For example, Pint is a legal identifier, 
    // even though it contains int, which is a keyword.

    // Use of two sequential underscore characters ( __ ) in an identifier, 
    // or a single leading underscore followed by a capital letter, 
    // is reserved for C++ implementations in all scopes. 
    // You should avoid using one leading underscore followed by a lowercase letter for names with file scope 
    // because of possible conflicts with current or future reserved identifiers.

    return 0;
}