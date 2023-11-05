// include/item.h

#pragma once

#include <fstream>

const int MAX_ITEMS = 5;
enum Relation {LESS, GREATER, EQUAL};

class Item
{
    public:
        Item();
        Relation comparedTo(Item) const;
        void print(std::ofstream&) const;
        void initialize(int number);
    private:
        int value;
};