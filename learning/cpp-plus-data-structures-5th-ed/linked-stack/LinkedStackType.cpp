// cpp-plus-data-structures-5th-ed/linked-stack/LinkedStackType.cpp

#include "LinkedStackType.h"
#include <stdexcept>

LinkedStackType::LinkedStackType()
{
    topPtr = nullptr;
}

LinkedStackType::~LinkedStackType()
{
    NodeType* tempPtr;

    while (topPtr != nullptr)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

void LinkedStackType::push(char item)
{
    if (isFull())
        throw FullStack();
    else
    {
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = topPtr;
        topPtr = location;
    }
}

void LinkedStackType::pop()
{
    if (isEmpty())
        throw EmptyStack();
    else
    {
        NodeType* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

char LinkedStackType::getTop()
{
    if (isEmpty())
        throw EmptyStack();
    else
        return topPtr->info;
}

bool LinkedStackType::isEmpty() const
{
    return (topPtr == nullptr);
}

bool LinkedStackType::isFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc e)
    {
        return true;
    }
}