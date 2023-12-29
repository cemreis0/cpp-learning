// learning/cpp-plus-data-structures-5th-ed/priority-queue/PQ.cpp

#include "PQ.h"

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = mew ItemType[max];
    length = 0;
}

template<class ItemType>
void PQType<ItemType>::makeEmpty()
{
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::dequeue(ItemType item)
{
    if (length == 0)
        throw EmptyPQ();
    else
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length - 1];
        length--;
        items.reheapDown(0, length-1);
    }
}

template<class ItemType>
void PQType<ItemType>::enqueue(ItemType item)
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        length++;
        items.elements[length-1] = item;
        items.reheapUp(0, length-1);
    }
}

template<class ItemType>
bool PQType<ItemType>::isFull() const
{
    return (length == maxItems);
}

template<class ItemType>
bool PQType<ItemType>::isEmpty() const
{
    return (length == 0);
}