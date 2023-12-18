// learning/cpp-plus-data-structures-5th-ed/polymorphism-with-virtual-functions/PolymorphismWithVirtualFunctions.cpp

#include <cstring>
#include <iostream>

class ItemType
{
    public:
        virtual int compareTo(ItemType) const; // virtual functions are used to implement run-time binding (dynamic binding)
        char lastName[50];
};

int ItemType::compareTo(ItemType item) const
{
    int result;

    result = std::strcmp(lastName, item.lastName);

    if (result < 0)
        return -1;
    else if (result > 0)
        return 1;
    else return 0;
}

// now derive a class NewItemType
class NewItemType : public ItemType
{
    public:
        int compareTo(NewItemType) const;
        // in addition to the inherited lastName member
        char firstName[50];
};

int NewItemType::compareTo(NewItemType item) const
{
    int result;

    result = std::strcmp(lastName, item.lastName);

    if (result < 0)
        return -1;
    else if (result > 0)
        return 1;
    else
    {
        result = std::strcmp(firstName, item.firstName);
        if (result < 0)
            return -1;
        else if (result > 0)
            return 1;
        else return 0;
    }
}

// let's assume the client program includes the following function
void printResults(ItemType& first, ItemType& second)
{
    if (first.compareTo(second) == -1)
        std::cout << "First comes before second." << std::endl;
    else
        std::cout << "First comes before second." << std::endl;
}

// it then executes the following code
ItemType item1, item2;
NewItemType item3, item4;

// both calls to printResults are valid.
// the first call invokes ItemType::printResults
// the second call invokes NewItemType::printResults
// printResults(item1, item2);
// printResults(item3, item4);





// if you have a pointer defined as a pointer to a base-class,
// and dynamically allocate storage using the base type, the pointer
// points to a base-class object. if you dynamically allocate storage
// using the derived type, the pointer points to a derived-class object

// example
class One
{
    public:
        virtual void Print() const;
};

class Two : public One
{
    public:
        void Print() const;
};

void PrintTest(One*);

int main()
{
    One* onePtr;
    onePtr = new One;

    std::cout << "Result of passing an object of class One" << std::endl;
    PrintTest(onePtr);

    onePtr = new Two;

    std::cout << "Result of passing an object of class Two" << std::endl;
    PrintTest(onePtr);
}

/*
Result of passing an object of class One:
Print member function of class One
Result of passing an object of class Two:
Print member function of class Two
*/

void PrintTest(One* ptr)
{
    ptr->Print();
}

void One::Print() const
{
    std::cout << "Print member function of class One" << std::endl;
}

void Two::Print() const
{
    std::cout << "Print member function of class Two" << std::endl;
}