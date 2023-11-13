// cpp-plus-data-structures-5th-ed/unsorted-list/UnsortedType.h

// ItemType:    the definition of the objects on the list
// MAX_ITEMS:   the maximum number of item on the list

#pragma once

#include "ItemType.h"

class UnsortedType
{
    public:
        UnsortedType();
        void makeEmpty();
        bool isFull();
        int getLength();
        ItemType getItem(ItemType item, bool &found);
        void putItem(ItemType item);
        void deleteItem(ItemType item);
        void resetList();
        ItemType getNextItem();
    private:
        int length;
        ItemType info[MAX_ITEMS]; // array
        int currentPos;
};