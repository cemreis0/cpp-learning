// cpp-plus-data-structures-5th-ed/sorted-list/SortedType.cpp

#include "SortedType.h"

SortedType::SortedType()
{
    length = 0;
}

void SortedType::makeEmpty()
{
    length = 0;
}

bool SortedType::isFull()
{
    return (length == MAX_ITEMS);
}

int SortedType::getLength()
{
    return length;
}

ItemType SortedType::getItem(ItemType item, bool &found)
{
    // binary search
    int midPoint;
    int first = 0;
    int last = length - 1;

    bool moreToSearch = first <= last;
    found = false;

    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        
        switch (item.comparedTo(info[midPoint]))
        {
            case -1:    last = midPoint - 1;
                        moreToSearch = first <= last;
                        break;
            case 1:     first = midPoint + 1;
                        moreToSearch = first <= last;
                        break;
            case 0:     found = true;
                        item = info[midPoint];
                        break;
        }
    }

    return item;
}

void SortedType::putItem(ItemType item)
{
    int location = 0;
    bool moreToSearch = (location < length);

    while (moreToSearch)
    {
        switch (item.comparedTo(info[location]))
        {
            case -1:    moreToSearch = false;
                        break;
            case 1:     location++;
                        moreToSearch = (location < length);
                        break;
        }
    }

    for (int i = length; i > location; i--)
        info[i] = info[i-1];

    info[location] = item;
    length++;
}

void SortedType::deleteItem(ItemType item)
{
    int location = 0;

    while (item.comparedTo(info[location]) != 0)
    {
        location++;
    }
    
    for (int i = location + 1; i < length; i++)
    {
        info[i - 1] = info[i];
    }

    length--;
}

void SortedType::resetList()
{
    currentPos = 0;
}

ItemType SortedType::getNextItem()
{
    currentPos++;
    return info[currentPos];
}