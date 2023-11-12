// cpp-plus-data-structures-5th-ed/unsorted-list/UnsortedType.cpp

#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
}

void UnsortedType::makeEmpty()
{
    length = 0;
}

bool UnsortedType::isFull()
{
    return (length == MAX_ITEMS);
}

int UnsortedType::getLength()
{
    return length;
}

ItemType UnsortedType::getItem(ItemType item, bool &found)
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
            case 1: location ++;
                    moreToSearch = (location < length);
                    break;
            case 0: found = true;
                    item = info[location];
                    break;
        }
    }

    return item;
}

void UnsortedType::putItem(ItemType item)
{
    info[length] = item;
    length++;
}

void UnsortedType::deleteItem(ItemType item)
{
    int location = 0;

    while (item.comparedTo(info[location]) != 0) // 0 means equal
    {
        location++;
    }

    info[location] = info[length-1];
    length - 1;
}

void UnsortedType::resetList(){
    currentPos = -1;
}

ItemType UnsortedType::getNextItem()
{
    currentPos++;
    return info[currentPos];
}