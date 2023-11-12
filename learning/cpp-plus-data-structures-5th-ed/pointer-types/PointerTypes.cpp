// cpp-plus-data-structures-5th-ed/pointer-types/PointerTypes.cpp

struct MoneyType
{
    int dollars;
    int cents;
};


int main()
{
    // static allocation, at compile time
    int alpha;
    int* intPointer1 = &alpha;
    *intPointer1 = 25; // indirect addressing, dereference operator used
    alpha = 10; // direct addressing

    // dynamic allocation, at run time
    int* intPointer2 = new int; // variables created by new reside on the heap (free store)

    // null pointer
    bool* truth = nullptr;
    float* money = nullptr;

    truth = new bool;
    *truth = true; // truth is now true
    money = new float;
    *money = 33.46; // money is now 33.46

    float* myMoney = new float; // myMoney is now unknown
    *myMoney = 99.86; // myMoney is now 99.86


    *myMoney = *money; // copies the value in the place pointed to by money into the place pointed to by myMoney
    myMoney = money; // copies the value in money into myMoney
    // the second copy of 33.46 cannot be accessed, no pointer points to it, it's called a memory leak, 
    // and the memory cells that cannot be accessed are called garbage

    // to avoid memory leak, we need to use delete keyword with new operator
    delete myMoney;
    myMoney = money;
    // the location originally pointed to by myMoney is no longer allocated
    // delete does not delete the pointer variable, but rather the variable to which the pointer points

    // pointers can be used with composite types
    MoneyType* moneyPtr = new MoneyType;
    // the arrow operator provides a shortcut for dereferencing a pointer and accessing a struct or class member
    moneyPtr->dollars = 3245;
    moneyPtr->cents = 33;

    return 0;
}