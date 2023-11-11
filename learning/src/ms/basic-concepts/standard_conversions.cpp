// src/ms/basic-concepts/standard_conversions.cpp

int main()
{
    // The following code causes conversions (in this example, integral promotions):
    long  long_num1, long_num2;
    int   int_num;

    // int_num promoted to type long prior to assignment.
    long_num1 = int_num;

    // int_num promoted to type long prior to multiplication.
    long_num2 = int_num * long_num2;

    // The result of a conversion is an l-value only if it produces a reference type.

    return 0;
}