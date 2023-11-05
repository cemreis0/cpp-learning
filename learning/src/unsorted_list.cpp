// src/unsorted_list.cpp

#include "../include/unsorted_list.h"

UnsortedList::UnsortedList()
{
    length = 0;
}

bool UnsortedList::isFull() const
{
    return (length == MAX_ITEMS);
}

int UnsortedList::getLength() const
{
    return length;
}

Item UnsortedList::getItem(Item item, bool& found)
{
    // if found, item's key matches an element's key in the list and a copy of that item is returned; otherwise, item is returned
    bool moreToSearch;
    int location = 0;
    found = false;

    moreToSearch = (location < length);

    while (moreToSearch && !found)
    {
        switch (item.comparedTo(info[location]))
        {
            case LESS :
            case GREATER :  location++;
                            moreToSearch = (location < length);
                            break;
            case EQUAL :    found = true;
                            item = info[location];
                            break;
        }
    }

    return item;
}

void UnsortedList::makeEmpty()
{
    length = 0;
}

void UnsortedList::putItem(Item item)
{
    info[length] = item;
    length++;
}

void UnsortedList::deleteItem(Item item)
{
    int location = 0;

    while (item.comparedTo(info[location]) != EQUAL)
    {
        location++;
    }

    info[location] = info[length - 1];
    length--;
}

void UnsortedList::resetList()
{
    currentPos = -1;
}

Item UnsortedList::getNextItem()
{
    currentPos++;
    return info[currentPos];
}