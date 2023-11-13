// cpp-plus-data-structures-5th-ed/linked-unsorted-list/ItemType.cpp

#include "ItemType.h"
#include <stdexcept>

ItemType::ItemType()
{
    value = 0;
}

// -1 self is less, 0 equal, 1 self is greater
int ItemType::comparedTo(ItemType item) const
{
    if (value < item.value) return -1;
    else if (value > item.value) return 1;
    else if (value == item.value) return 0;
    else throw std::invalid_argument("An error occured comparing items.");
}

void ItemType::print(std::ofstream &out) const
{
    out << value << std::endl;
}

void ItemType::initialize(int number)
{
    value = number;
}