// cpp-plus-data-structures-5th-ed/linked-unsorted-list/LinkedUnsortedType.cpp

#include "LinkedUnsortedType.h"

LinkedUnsortedType::LinkedUnsortedType()
{
    length = 0;
    listData = nullptr;
}

void LinkedUnsortedType::makeEmpty()
{
    NodeType* tempPtr;

    while (listData != nullptr)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

bool LinkedUnsortedType::isFull() const
{
    NodeType* location;

    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(const std::bad_alloc e)
    {
        return true;
    }
    
}

int LinkedUnsortedType::getLength()
{
    return length;
}

ItemType LinkedUnsortedType::getItem(ItemType item, bool& found)
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    found = false;
    moreToSearch = (location != nullptr);

    while (moreToSearch && !found)
    {
        switch (item.comparedTo(location->info))
        {
            case -1:
            case 1: location = location->next;
                    moreToSearch = (location != nullptr);
                    break;
            case 0: found = true;
                    item = location->info;
                    break;
        }
    }

    return item;
}

void LinkedUnsortedType::putItem(ItemType item)
{
    NodeType* location; // declare a pointer to a node

    location = new NodeType; // get a new node
    location->info = item; // store the item in the new node
    location->next = listData; // store the address of the first node in the next field of node
    listData = location; // store address of new node into external pointer
    length++; // increment the length of list by one
}

void LinkedUnsortedType::deleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    // locate node to be deleted
    if (item.comparedTo(location->info) == 0)
    {
        tempLocation = location;
        listData = listData->next; // delete the first node
    }
    else
    {
        while (item.comparedTo((location->next)->info) != 0)
            location = location->next;
        
        // delete location at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    
    delete tempLocation;
    length--;
}

void LinkedUnsortedType::resetList()
{
    currentPos = nullptr;
}

ItemType LinkedUnsortedType::getNextItem()
{
    if (currentPos == nullptr)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    
    return currentPos->info;
}