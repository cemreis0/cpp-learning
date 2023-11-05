// include/unsorted_list.h

#pragma once

#include "item.h"

class UnsortedList
{
    public:
        UnsortedList();
        void makeEmpty();
        bool isFull() const;
        int getLength() const;
        Item getItem(Item item, bool& found);
        void putItem(Item item);
        void deleteItem(Item item);
        void resetList();
        Item getNextItem();
    private:
        int length;
        Item info[MAX_ITEMS];
        int currentPos;
};