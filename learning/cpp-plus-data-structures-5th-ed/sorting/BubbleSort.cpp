// learning/cpp-plus-data-structures-5th-ed/sorting/BubbleSort.cpp

/*
(general algorithm)
bubbleSort
set current tı the index of the first item in the array
while more items in the unsorted part of the array
    "bubble up" the smallest item in the unsorted part, causing intermediate swaps as needed
    shrink the unsorted part of the array by incrementing current
*/

/*
(bubbling up)
bobbleUp(values, startIndex, endIndex)
for index going from endIndex DOWNTO startIndex+1
    if values[index] < values [index-1]
        swap(values[index], values[index-1])
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
void bubbleUp(ItemType values[], int startIndex, int endIndex)
{
    for int(index = startIndex; index < endIndex; index++)
        if (values[index] < values[index-1])
            swap(values[index], values[index-1]);
}

template<class ItemType>
void bubbleSort(ItemType values[], int numValues)
{
    int current = 0;
    while (current < numValues-1)
    {
        bubbleUp(values, current, numValues);
        current++;
    }
}

// bubble sort may end before making n-1 calls
// we could quit before the maximum number of iterations if bubbleUp returns a bool flag sorted
template<class ItemType>
void bubbleUp2(ItemType values[], int startIndex, int endIndex, bool& sorted)
{
    sorted = true;
    for int(index = startIndex; index < endIndex; index++)
        if (values[index] < values[index-1])
        {
            swap(values[index], values[index-1]);
            sorted = false;
        }
}

template<class ItemType>
void shortBubbleSort(ItemType values[], int numValues)
{
    int current = 0;
    bool sorted = false;
    while (current < numValues-1 && !sorted)
    {
        bubbleUp2(values, current, numValues-1, sorted);
        current++;
    }
}