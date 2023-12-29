// cpp-plus-data-structures-5th-ed/unsorted-list/UnsortedType.cpp

#include "UnsortedType.h"

template<class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

template<class ItemType>
void UnsortedType<ItemType>::makeEmpty()
{
    length = 0;
}

template<class ItemType>
bool UnsortedType<ItemType>::isFull()
{
    return (length == MAX_ITEMS);
}

template<class ItemType>
int UnsortedType<ItemType>::getLength()
{
    return length;
}

template<class ItemType>
ItemType UnsortedType<ItemType>::getItem(ItemType item, bool &found)
{
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.comparedTo(info[location]))
        {
            case -1:
            case 1: location++;
                moreToSearch = (location < length);
                break;
            case 0: found = true;
                item = info[location];
                break;
        }
    }

    return item;
}

template<class ItemType>
void UnsortedType<ItemType>::putItem(ItemType item)
{
    info[length] = item;
    length++;
}

template<class ItemType>
void UnsortedType<ItemType>::deleteItem(ItemType item)
{
    int location = 0;

    while (item.comparedTo(info[location]) != 0) // 0 means equal
    {
        location++;
    }

    info[location] = info[length - 1];
    length--;
}

template<class ItemType>
void UnsortedType<ItemType>::resetList()
{
    currentPos = -1;
}

template<class ItemType>
ItemType UnsortedType<ItemType>::getNextItem()
{
    currentPos++;
    return info[currentPos];
}

// Explicit instantiation of the template for the specific ItemType
template class UnsortedType<ItemType>;
