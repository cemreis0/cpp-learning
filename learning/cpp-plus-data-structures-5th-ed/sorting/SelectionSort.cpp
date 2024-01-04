// learning/cpp-plus-data-structures-5th-ed/sorting/SelectionSort.cpp

/*
(general algorithm)
selectionSort
set current to the index of the first item in the array
while more items in the unsorted part of the array
    find the index of the smallest unsorted item
    swap the current item with the smallest unsorted one
    shrink the unsorted part of the array by incrementing current
*/

/*
(locate the smallest value in the unsorted part)
int minIndex(values, startIndex, endIndex)
set indexOfMin to startIndex
for index going from startIndex + 1 endIndex
    if values[index] < values[indexOfMin]
        set indexOfMin to index
return indexOfMin
*/

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
int minIndex(ItemType values[], int startIndex, int endIndex)
{
    int indexOfMin = startIndex;
    for (int index = startIndex; index < endIndex; index++)
        if (values[index] < values[indexOfMin])
            indexOfMin = index;
    return indexOfMin;
}

template<class ItemType>
void selectionSort(ItemType values[], int numValues)
{
    int endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++)
        swap(values[current], values[minIndex(values, current, endIndex)]);
}