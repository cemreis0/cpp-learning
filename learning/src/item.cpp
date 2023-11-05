// src/item.cpp

#include "../include/item.h"

Item::Item()
{
    value = 0;
}

Relation Item::comparedTo(Item otherItem) const
{
    if (value < otherItem.value)
        return LESS;
    else  if (value > otherItem.value)
        return GREATER;
    else
        return EQUAL;
}

void Item::initialize(int number)
{
    value = number;
}

void Item::print(std::ofstream& out) const
{
    out << value << std::endl;
}