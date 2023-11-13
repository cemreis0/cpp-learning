// ms/built-in-types/built_in_types.cpp

int main()
{
    // nullptr
    // use nullptr for a pointer, avoid using NULL or 0

    // void
    /*
    When used as a function return type, the void keyword specifies that the function doesn't return a value.
    When used for a function's parameter list, void specifies that the function takes no parameters.
    When used in the declaration of a pointer, void specifies that the pointer is "universal."
    */
    // As a matter of style, the C++ Core Guidelines recommend you don't use void to 
    // specify an empty formal parameter list. 

    // bool
    // these expressions are not allowed: bool++, bool--, ++ bool, --bool

    // numerical limits
    // The two standard include files, <limits.h> and <float.h>, 
    // define the numerical limits, or minimum and maximum values that a variable of a given type can hold.

    return 0;
}