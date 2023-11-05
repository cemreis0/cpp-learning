class Fraction
{
private:
    int num;
    int denom;
public:
    void Initialize(int numerator, int denominator)
    {
        // function: initialize the fraction
        // pre: numerator and denominator are in reduced form
        // post: fraction is initialized
        num = numerator;
        denom = denominator;
    }

    int GetDenominator()
    {
        // function: return the value of denominator
        // pre: fraction has been initialized
        // post: denominator is returned
        return denom;
    }

    int GetNumerator()
    {
        // function: return the value of numerator
        // pre: fraction has been initialized
        // post: numerator is returned
        return num;
    }

    bool IsZero()
    {
        // function: determine if fraction is zero
        // pre: function has been initialized
        // post: return true if numerator is zero; false otherwise
        return (num == 0);
    }

    bool IsNotProper()
    {
        // function: determine if the fraction is a proper fraction
        // pre: fraction has been initialized
        // post: return true if fraction is greater than or equal to 1; false otherwise
        return (num >= denom);
    }

    int ConvertToProper()
    {
        // function: convert the fraction to a whole number and a fractional part
        // pre: fraction has been initialized, is in reduced form and is not a proper fraction
        // post: return whole number; remaining fraction is original fraction minus the whole number; fraction is in reduced form
        int result;
        result = num / denom;
        num = num % denom;
        if (num == 0)
            denom = 1;
        return result;
    }

};
