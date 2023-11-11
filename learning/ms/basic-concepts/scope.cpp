// src/ms/basic_concepts.cpp

#include <iostream>
using namespace std;

int main()
{
    // There are six kinds of scope

    // Global scope. Declared outside of a class, function or  namespace.
    // The scope extends from the point of declaration to the end of file in which they are declared.

    // Namespace scope. Declared within a namespace, outside of any class or function block or enum definition.
    // The scope extends from the point of declaration to the end of the namespace.

    // Local scope. Declared within a function or lambda. Parameter names have local scope.
    // The scope extends from the point of declaration to the end of the function or lambda body.

    // Class scope. Declared with a class.
    // The scope extends throughout the class definition regardless of the point of declaration.
    // Class member accessibility is further controlled by the public, private and protected keywords.
    // Public or protected members can be accessed only by the member-selection operators (. or ->) or 
    // pointer-to-member operators (.* or ->*).

    // Statement scope. Names declared in a for, if, while, or switch statement are visible until the end of the statement block.

    // Function scope. A label has function scope, which means it is visible throughout a function body even before its point of declaration.

    // Hiding names
    // outer scope contains local-scope i
    int i = 0;
    cout << "i: " << i << endl;
    {
        // inner scope contains local-scope i and j
        int i = 7, j = 3;
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
    }
    cout << "i: " << i << endl;

    // Hiding class names
    // You can hide class names by declaring a function, object or variable, or enumerator in the same scope. 
    // However, the class name can still be accessed when prefixed by the keyword class.

    // Hiding names with global scope
    // You can hide names with global scope by explicitly declaring the same name in block scope. 
    // However, global-scope names can be accessed using the scope-resolution operator (::).

    

    return 0;
}