// learning/cpp-plus-data-structures-5th-ed/heap/Heap.cpp

#include "Heap.h"

template<class ItemType>
void swap(ItemType item1, ItemType item2);

template<class ItemType>
void HeapType<ItemType>::reheapDown(int root, int bottom)
// post: heap property is restored
{
    int maxChild, rightChild, leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (elements[root] < elements[maxChild])
        {
            swap(elements[root], elements[maxChild]);
            reheapDown(maxChild, bottom);
        }
    }
}

template<class ItemType>
void HeapType<ItemType>::reheapUp(int root, int bottom)
// post: heap property is restored
{
    int parent;

    if (bottom > root)
    {
        parent = (bottom - 1) / 2;
        if (elements[parent] < elements[bottom])
        {
            swap(elements[parent], elements[bottom]);
            reheapUp(root, parent);
        }
    }
}