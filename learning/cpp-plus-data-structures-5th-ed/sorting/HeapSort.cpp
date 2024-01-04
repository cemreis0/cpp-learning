// learning/cpp-plus-data-structures-5th-ed/sorting/HeapSort.cpp

/*
buildHeap
for index going from first nonleaf node up to the root node
    reheapDown(values, index, numValues-1)
*/

/*
sortNodes
for index going from last node up to next-to-root node
    swap data in root node with values[index]
    reheapDown(values, 0, index-1)
*/

#include "heap/Heap.h"

// swap two data values between array locations
template<class ItemType>
inline void swap(ItemType& item1, ItemType& item2)
{
    ItemType tempItem;

    tempItem = item1;
    item1 = item2;
    item2 = tempItem;
}

template<class ItemType>
void heapSort(ItemType values[], int numValues)
{
    int index;

    // convert the array of values into a heap
    for (index = numValues/2-1; index >= 0; index--)
        reheapDown(values, index, numValues-1);
    
    // sort the array
    for (index = numValues-1; index >= 1; index--)
    {
        swap(values[0], values[index]);
        reheapDown(values, 0, index-1);
    }
}