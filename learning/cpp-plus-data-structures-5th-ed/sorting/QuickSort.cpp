// learning/cpp-plus-data-structures-5th-ed/sorting/QuickSort.cpp

/*
(general algorithm)
quickSort
if there is more than one item in values[first]...values[last]
    select splitVal
    split the array so that
        values[first]...values[splitPoint-1] <= splitVal
        values[splitPoint] = splitVal
        values[splitPoint+1]...values[last] > splitVal
    quickSort to left half
    quickSort to left half
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
void split(ItemType values[], int first, int last, int& splitPoint)
{
    ItemType splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;

    do
    {
        onCorrectSide = true;

        // move first towards last
        while (onCorrectSide)
        {
            if (values[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }
        }

        onCorrectSide = (first <= last);

        // move last towards first
        while (onCorrectSide)
        {
            if (values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }
        }

        if (first < last)
        {
            swap(values[first], values[last]);
            first++;
            last--;
        }
    } while (first <= last);

    splitPoint = last;
    swap(values[saveFirst], values[splitPoint]);
}

template<class ItemType>
void quickSort(ItemType values[], int first, int last)
{
    if (first < last)
    {
        int splitPoint;

        split(values, first, last, splitPoint);

        quickSort(values, first, splitPoint-1);
        quickSort(values, splitPoint+1, last);
    }
}

// another splitting algorithm, take the value in the middle of the array
// works especially for a nearly sorted array
template<class ItemType>
void split2(ItemType values[], int first, int last, int& splitPt1, int& splitPt2)
{
    ItemType splitVal = values[(first+last)/2];
    int saveFirst = first;
    bool onCorrectSide;

    first++;

    do
    {
        onCorrectSide = true;

        // move first towards last
        while (onCorrectSide)
        {
            if (values[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }
        }

        onCorrectSide = true;

        // move last towards first
        while (onCorrectSide)
        {
            if (values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }
        }

        if (first < last)
        {
            swap(values[first], values[last]);
            first++;
            last--;
        }
    } while (first <= last);

    splitPt1 = first;
    splitPt2 = last;
}

// adjust quickSort accordingly
template<class ItemType>
void quickSort2(ItemType values[], int first, int last)
{
    if (first < last)
    {
        int splitPt1, splitPt2;

        split(values, first, last, splitPt1, splitPt2);

        if (splitPt1 < last)        
            quickSort(values, splitPt1, last);
        if (first < splitPt2)
            quickSort(values, splitPt1, last);
    }
}
