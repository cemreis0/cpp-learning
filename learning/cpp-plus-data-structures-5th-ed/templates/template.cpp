// cpp-plus-data-structures-5th-ed/templates/template.cpp

/*
in the definitions of different stack below,
the data type name enclosed in angle brackets
is the "actual parameter" (or argument) to the template.

at compile time, the compiler generates (instantiates)
three distinct class types and gives its own internal name
to each type.

in terminology, three new class types are called "template classes".
*/

// client code
#include "template.h"

// several stacks whose components are of different data types
StackType<int> intStack;
StackType<float> floatStack;
StackType<char> charStack;

// intStack.push(35);
// floatStack.push(3542.234);
// charStack('a');

/*
how to handle the definitions of member functions?
we neede to write them as function templates.
*/

// push function example
template <class ItemType>
void StackType<ItemType>::push(ItemType item)
{
    if (isFull())
        throw FullStack();
    top++;
    items[top] = item;
}

/*
the compiler cannot instantiate a function template unless it knows
the actual parameter to the template, and this actual parameter
appears in the client code.

one general solution is to compile the client code and the member
functions at the same time.

a popular technique is to place both the class definition and the
member functions into the same file: header.

another technique involves giving the include directive for the
implementation file at the end of the header file.
*/