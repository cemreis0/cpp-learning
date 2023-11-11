// src/ms/lexical-conventions/numeric_boolean_and_pointer_literals.cpp

#include <iostream>
using namespace std;

int main()
{
    // A literal is a program element that directly represents a value.

    const int answer = 42;      // integer literal
    double d = sin(108.87);     // floating point literal passed to sin function
    bool b = true;              // boolean literal
    MyClass* mc = nullptr;      // pointer literal

    // Sometimes it's important to tell the compiler how to interpret a literal, or what specific type to give to it. 
    // It's done by appending prefixes or suffixes to the literal.
    // For example,
    // The prefix 0x tells the compiler to interpret the number that follows it as a hexadecimal value, for example 0x35
    // The ULL suffix tells the compiler to treat the value as an unsigned long long type, as in 5894345ULL

    // Integer Literals
    // You can specify integer literals in decimal, binary, octal, or hexadecimal form. 
    // You can optionally specify an integer literal as unsigned, and as a long or long long type, by using a suffix.
    // When no prefix or suffix is present, the compiler will give an integral literal value type int (32 bits), 
    // if the value will fit, otherwise it will give it type long long (64 bits).

    // int i = 157;         // Decimal literal
    int j = 0198;           // Not a decimal number; erroneous octal literal
    int k = 0365;           // Leading zero specifies octal literal, not decimal
    int m = 36'000'000;     // digit separators make large values more readable

    // Octal integral literal, range 0-7
    int i = 0377;       // Octal literal
    int j = 0397;       // Error: 9 is not an octal digit

    // Hexadecimal integral literal, start with 0x or 0X, followed by a sequence of digits 0-9 and a-f (or A-F), a-f represent values in range 10-15
    int i = 0x3fff;   // Hexadecimal literal
    int j = 0X3FFF;   // Equal to i

    // Unsigned type, use u (or U) suffix, to specify a long type use l (or L) suffix, to specify a 64-bit integral type use ll (or LL) suffix
    unsigned val_1 = 328u;                          // Unsigned value
    long val_2 = 0x7FFFFFL;                         // Long value specified as hex literal
    unsigned long val_3 = 0776745ul;                // Unsigned long value
    auto val_4 = 108LL;                             // signed long long
    auto val_4 = 0x8000000000000000ULL << 16;       // unsigned long long

    // Digit separators
    long long i = 24'847'458'121; // easier for a human to read

    // Floating Point Literals
    // Floating-point literals have a significand (sometimes called a mantissa), which specifies the value of the number.
    // They have an exponent, which specifies the magnitude of the number.
    // And, they have an optional suffix that specifies the literal's type.
    // The significand is specified as a sequence of digits followed by a period, 
    // followed by an optional sequence of digits representing the fractional part of the number. 
    // For example:
    float a = 18.56;
    float b = 18.;
    // The exponent, if present, specifies the magnitude of the number as a power of 10, as shown in the following example:
    float a = 18.46e0;      // 18.46
    float b = 18.46e1;      // 184.6
    float c = 18.56e-1;     // 1.856
    // Floating-point literals default to type double. By using the suffixes f or l or F or L, the literal can be specified as float or long double.

    // Boolean Literals
    bool isValid = true;
    bool isOk = false;

    // Pointer literal
    int* intPtr = nullptr;

    // Binary literals
    // A binary literal can be specified by the use of the 0B or 0b prefix, followed by a sequence of 1's and 0's:
    auto x = 0B001101; // int
    auto y = 0b000001; // int

    // Avoid using literals as "magic constants"
    // if (num < 100)
    //      return "Success";
    // named constants like "MAXIMUM_ERROR_THRESHOLD" or string message = "Success" should be used

    return 0;
}