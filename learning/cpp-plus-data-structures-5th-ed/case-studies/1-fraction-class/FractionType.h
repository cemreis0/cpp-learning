// FractionType Header File

#pragma once

class FractionType
{
    public:
        void initialize(int numerator, int denominator);
        // function: initialize the fraction
        // pre: numerator and denominator are in reduced form
        // post: fraction is initialized

        int getNumerator();
        // function: return the value of the numerator
        // pre: fraction has been initialized
        // post: numerator is returned

        int getDenominator();
        // function: return the value of the denominator
        // pre: fraction has been initialized
        // post: denominator is returned

        bool isZero();
        // function: determine if fraction is zero
        // pre: fraction has been initialized
        // post: return true if fraction is zero, false otherwise

        bool isProper();
        // function: determine if fraction < 1
        // pre: fraction has been initialized
        // post: return true if fraction < 1, false otherwise

        int convertToProper();
        // function: converts the fraction to a whole number and a fractional part
        // pre: fraction has been initialized, is in reduced form, is not a proper fraction
        // post:    return whole number,
        //          remaining fraction is original minus whole part,
        //          fraction is in reduced form

    private:
        int num, denom;
};