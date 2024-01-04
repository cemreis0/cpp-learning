// learning/cpp-plus-data-structures-5th-ed/sorting/MergeSort.cpp

/*
(general algorithm)
mergeSort
cut the array in half
sort the left half
sort the right half
merge the two sorted halves into one sorted array
*/

/*
(recursive approach)
mergeSortRecursive
cut the array in half
mergeSort the left half
mergeSort the right half
merge the two sorted halves into one sorted array

base case: when the half does not have more than one element
*/

/*
(merge two sorted arrays together)
merge(uses a local array, tempArray)
set saveFirst to leftFirst
set index to leftFirst
while more items in left half AND more items in right half
    if values[leftFirst] < values[rightFirst]
        set tempArray[index] to values[leftFirst]
        increment leftFirst
    else
        set tempArray[index] to values[rightFirst]
        increment rightFirst
    increment index
copy any remaining items from left half to tempArray
copy any remaining items from right half to tempArray
copy the sorted elements from tempArray back into values
*/

template<class ItemType>
void merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
    ItemType tempArray[MAX_ITEMS];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst] < values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while (leftFirst <= leftLast)
    {
        tempArray[index] = values[leftFirst];
        leftFirst;
        index++;
    }

    while (rightFirst <= rightLast)
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}

template<class ItemType>
void mergeSort(ItemType values[], int first, int last)
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        mergeSort(values, first, middle);
        mergeSort(values, middle+1, last);
        merge(values, first, middle, middle+1, last);
    }
}