// cpp-plus-data-structures-5th-ed/stack/StackType.cpp

#include "StackType.h"

StackType::StackType()
{
    top = -1;
}

bool StackType::isEmpty() const
{
    return (top == -1);
}

bool StackType::isFull() const
{
    return (top == MAX_ITEMS - 1);
}

void StackType::push(char item)
{
    if (isFull())
        throw FullStack();
    top++;
    items[top] = item;
}

void StackType::pop()
{
    if (isEmpty())
        throw EmptyStack();
    top--;
}

char StackType::getTop() const
{
    if (isEmpty())
        throw EmptyStack();
    return items[top];
}