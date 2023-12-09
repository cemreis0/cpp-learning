// cpp-plus-data-structures-5th-ed/queue/QueType.cpp

#include "QueType.h"

QueType::QueType(int max = 500)
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new int[maxQue];
}

QueType::~QueType()
{
    delete [] items;
}

void QueType::makeEmpty()
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::isEmpty() const
{
    return (front == rear);
}

bool QueType::isFull() const
{
    return ((rear + 1) % maxQue == front);
}

void QueType::enqueue(int item)
{
    if (isFull())
        throw FullQueue();
    else
    {
        rear = (rear + 1) % maxQue;
        items[rear] = item;
    }
}

// dequeue does not actually remove the value of item from the array
// it no longer exists in the queue, however, and cannot be accessed
void QueType::dequeue(int& item)
{
    if (isEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}