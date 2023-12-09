// cpp-plus-data-structures-5th-ed/stack/StackTypeDynamicAlloc.cpp

#include "StackTypeDynamicAlloc.h"

StackTypeDynamicAlloc::StackTypeDynamicAlloc(int max = 100)
{
    maxStack = max;
    top = -1;
    items = new char[maxStack];
}

StackTypeDynamicAlloc::~StackTypeDynamicAlloc()
{
    delete [] items;
}