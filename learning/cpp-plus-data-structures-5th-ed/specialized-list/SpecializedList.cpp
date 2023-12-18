// learning/cpp-plus-data-structures-5th-ed/specialized-list/SpecializedList.cpp

#include "SpecializedList.h"

SpecializedList::SpecializedList()
{
    list = nullptr;
    length = 0;
}

void SpecializedList::resetForward()
{
    currentNextPos = 0;
}

void SpecializedList::getNextItem(int& item, bool& finished)
{
    if (currentNextPos == nullptr)
        currentNextPos = list->next;
    else
        currentNextPos = currentNextPos->next;
    item = currentNextPos->info;
    finished = (currentNextPos == list);
}

void SpecializedList::resetBackward()
{
    currentBackPos = 0;
}

void SpecializedList::getPriorItem(int& item, bool& finished)
{
    if (currentBackPos == nullptr)
        currentBackPos = list;
    else
        currentBackPos = currentBackPos->back;
    item = currentBackPos->info;
    finished = (currentBackPos->next);
}

int SpecializedList::getLength()
{
    return length;
}

void SpecializedList::putFront(int item)
{
    NodeType* newNode;
    newNode = new NodeType;
    newNode->info = item;

    if (list == nullptr)
    {
        newNode->back = newNode;
        newNode->next = newNode;
        list = newNode;
    }
    else
    {
        newNode->back = list;
        newNode->next = list->next;
        list->next->back = newNode;
        list->next = newNode;
    }
}

void SpecializedList::putEnd(int item)
{
    // identical to putFront except for the external pointer list
    putFront(item);
    list = list->next;
}