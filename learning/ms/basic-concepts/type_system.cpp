// src/ms/basic-concepts/type_system.cpp

int main()
{
    // Every variable, function argument and function return must have a type.
    // Either built-in types like int or double, or programmer-defined ones like a class or struct

    // Terminology
    // Scalar type: A type that holds a defined range. Integral and floating point values,
    // numeration type members, pointer types, pointer-to-member types.

    // Compound type: A type that isn't a scalar type. Compound types include array types, function types, 
    // class (or struct) types, union types, enumerations, references, and pointers to non-static class members.

    // Variable: The symbolic name of a quantity of data. In C++, variable is often used to refer to instances 
    // of scalar data types, whereas instances of other types are typically called objects.

    // Object: Depending on concept, object refers to an instance of a class or a struct, but in general sense, 
    // it includes all types, even scalar variables.

    // POD type (plain old data): Types that are scalar or are POD classes.
    // POD classes do not have any static data members, no user-defined constructors, user-defined destructors, 
    // user-defined assignment operators, no virtual functions, no base class, and no private or protected non-static data members.

    return 0;
}