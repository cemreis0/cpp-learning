// src/pointer_types.cpp

#include <iostream>

int main()
{
    // static allocation
    int alpha;
    int* intPointer;
    intPointer = &alpha;
    *intPointer = 25; // dereference operator

    std::cout << *intPointer << std::endl;

    // dynamic allocation
    intPointer = new int;

    bool* truth = NULL;
    truth = new bool;
    *truth = true;

    float* money = NULL;
    money = new float;
    *money = 33.46;
    
    std::cout << *money << std::endl;

    float* myMoney = new float;
    *myMoney = 99.86;

    *myMoney = *money; // copy the value in the place pointed to by money into the place pointed to by myMoney
    myMoney = money; // copy the value in money into myMoney, causes memory leak, *myMoney cannot be accessed, no pointers point to it, it is now a garbage

    delete myMoney; // prevents memory leak
    myMoney = money; // delete does not delete the pointer variable, but rather the variable to which the pointer points

    // using pointers with composite types
    struct Money
    {
        int dollars;
        int cents;
    };
    Money* moneyPtr = new Money;
    moneyPtr->dollars = 3245;
    moneyPtr->cents = 33;
}