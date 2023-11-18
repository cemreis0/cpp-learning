// ms/declarations-and-definitions/aliases_and_typedefs.cpp

int main()
{
    // You can use an alias declaration to declare a name to use as a synonym for a previously declared type
    // syntax:
    // using identifier = type;

    // example:
    // C++11
    using counter = long;
    // C++03 equivalent:
    // typedef long counter;

    // Aliases also work with function pointers
    // C++11
    using func = void(*)(int);
    // C++03 equivalent:
    // typedef void (*func)(int);
    // func can be assigned to a function pointer value
    void actual_function(int arg) { /* some code */ }
    func fptr = &actual_function;

    // A limitation of the typedef mechanism is that it doesn't work with templates. 
    // However, the type alias syntax in C++11 enables the creation of alias templates:
    template<typename T> using ptr = T*;
    // the name 'ptr<T>' is now an alias for pointer to T
    ptr<int> ptr_int;

    return 0;
}