// cpp-plus-data-structures-5th-ed/unsorted-list/ItemType.h

#pragma once

#include <fstream>

const int MAX_ITEMS = 5;

class ItemType
{
    public:
        ItemType();
        int comparedTo(ItemType item) const;
        void print(std::ofstream &out) const;
        void initialize(int number);
    private:
        int value;
};