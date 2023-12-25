// FractionType Implementation File

#include "FractionType.h"

void FractionType::initialize(int numerator, int denominator)
// function: initialize the fraction
// pre: numerator and denominator are in reduced form
// post:    numerator is stored in num,
//          denominator is stored in denom
{
    num = numerator;
    denom = denominator;
}

int FractionType::getNumerator()
// function: return the value of the numerator
// pre: fraction has been initialized
// post: numerator is returned
{
    return num;
}

int FractionType::getDenominator()
// function: return the value of the denominator
// pre: fraction has been initialized
// post: denominator is returned
{
    return denom;
}

bool FractionType::isZero()
// function: determine if fraction is zero
// pre: fraction has been initialized
// post: return true if num is zero, false otherwise
{
    return (num == 0);
}

bool FractionType::isProper()
// function: determine if fraction < 1
// pre: fraction has been initialized
// post: return true if num is less than denom, false otherwise
{
    return (num < denom);
}

int FractionType::convertToProper()
// function: converts the fraction to a whole number and a fractional part
// pre: fraction has been initialized, is in reduced form, is not a proper fraction
// post:    return num divided by denom,
//          num is num % denom
{
    int result;
    result = num / denom;
    num = num % denom;
    if (num == 0)
        denom = 1;
    return result;
}