// learning/cpp-plus-data-structures-5th-ed/sorting/InsertionSort.cpp

/*
(general algorithm)
insertionSort
for count going from 0 through numValues-1
    insertItem(values, 0, count)
*/

/*
(inserting an item in appropriate place)
insertItem(values, startIndex, endIndex)
set finished to false
set current to endIndex
set moreToSearch to (current does not equal startIndex)
while moreToSearch AND NOT finished
    if values[current] < values[current-1]
        swap(values[current], values[current-1])
        decrement current
        set moreToSearch to (current does not equal startIndex)
    else
        set finished to true
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
void insertItem(ItemType values[], int startIndex, int endIndex)
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while (moreToSearch && !finished)
    {
        if (values[current] < values[current-1])
        {
            swap(values[current], values[current-1])
            current--,
            moreToSearch = (current != startIndex);
        }
        else
            finished = true;
    }
}

template<class ItemType>
void insertionSort(ItemType values[], int numValues)
{
    for (int count = 0; count < numValues; count++)
        insertItem(values, 0, count);
}