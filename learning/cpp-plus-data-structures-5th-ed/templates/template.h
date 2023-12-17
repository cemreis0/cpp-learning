// cpp-plus-data-structures-5th-ed/templates/template.h

/*
template: a generic c++ language construct that allows
the compiler to generate multiple versions of a class
type or a function by allowing parameterized types.

a template allows you to write a description of a class
type with "blanks" left in the description to be filled
in by the client code.

just as variables are the parameters to functions,
types are parameters to templates.
*/

// ------------------
// example: stack adt
// ------------------

/*
this code is known as a class template.
ItemType is called the "formal parameter" to the template.
The rest of the code is in template.cpp
*/

template<class ItemType>

class StackType
{
    public:
        StackType();
        bool isEmpty() const;
        bool isFull() const;
        void push(ItemType item);
        void pop();
        ItemType getTop() const;
    private:
        static const int MAX_ITEMS = 5;
        int top;
        ItemType items[MAX_ITEMS];
}