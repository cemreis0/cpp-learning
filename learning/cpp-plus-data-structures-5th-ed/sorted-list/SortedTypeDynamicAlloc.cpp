// cpp-plus-data-structures-5th-ed/sorted-list/SortedTypeDynamicAlloc.cpp

#include "SortedTypeDynamicAlloc.h"

SortedTypeDynamicAlloc::SortedTypeDynamicAlloc(int max = 500)
{
    // the idea is to use the new operator to allocate an array of exactly the desired size
    maxList = max;
    length = 0;
    info = new ItemType[maxList];
}

SortedTypeDynamicAlloc::SortedTypeDynamicAlloc()
{
    maxList = 500;
    length = 0;
    info = new ItemType[maxList];
}

SortedTypeDynamicAlloc::~SortedTypeDynamicAlloc()
{
    delete [] info;
}

void SortedTypeDynamicAlloc::makeEmpty()
{
    length = 0;
}

bool SortedTypeDynamicAlloc::isFull()
{
    return (length == maxList);
}

int SortedTypeDynamicAlloc::getLength()
{
    return length;
}

ItemType SortedTypeDynamicAlloc::getItem(ItemType item, bool &found)
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

void SortedTypeDynamicAlloc::putItem(ItemType item)
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

void SortedTypeDynamicAlloc::deleteItem(ItemType item)
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

void SortedTypeDynamicAlloc::resetList()
{
    currentPos = 0;
}

ItemType SortedTypeDynamicAlloc::getNextItem()
{
    currentPos++;
    return info[currentPos];
}