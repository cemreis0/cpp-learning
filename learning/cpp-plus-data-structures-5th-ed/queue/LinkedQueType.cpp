// cpp-plus-data-structures-5th-ed/queue/LinkedQueType.cpp

#include "LinkedQueType.h"
#include <stdexcept>


LinkedQueType::LinkedQueType()
{
    front = nullptr;
    rear = nullptr;
}

LinkedQueType::~LinkedQueType()
{
    makeEmpty();
}

void LinkedQueType::makeEmpty()
{
    NodeType* tempPtr;

    while (front != nullptr)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }

    rear = nullptr;
}

void LinkedQueType::enqueue(int item)
{
    if (isFull)
        throw FullQueue();
    else
    {
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = item;
        newNode->next = nullptr;
        if (rear == nullptr)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}

void LinkedQueType::dequeue(int& item)
{
    if (isEmpty())
        throw EmptyQueue();
    else
    {
        NodeType* tempPtr;
        tempPtr = front;
        item = front->info;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete tempPtr;
    }
}

bool LinkedQueType::isEmpty() const
{
    return (front == nullptr);
}

bool LinkedQueType::isFull() const
{
    NodeType* location;

    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(const std::bad_alloc)
    {
        return true;
    }
    
}