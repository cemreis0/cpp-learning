// cpp-plus-data-structures-5th-ed/queue/CountedQueType.cpp

#include "CountedQueType.h"

CountedQueType::CountedQueType(int max = 500) : QueType(max) // constructor initializer
{
    int length = 0;
}

void CountedQueType::enqueue(int item)
{
    try
    {
        QueType::enqueue(item);
        length++;
    }
    catch(FullQueue)
    {
        throw FullQueue();
    }
}

void CountedQueType::dequeue(int& item)
{
    try
    {
        QueType::dequeue(item);
        length--;
    }
    catch(EmptyQueue)
    {
        throw EmptyQueue();
    }
}

int CountedQueType::getLength() const
{
    return length;
}