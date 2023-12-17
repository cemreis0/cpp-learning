// cpp-plus-data-structures-5th-ed/linked-sorted-list/LinkedSortedType.cpp

#include "LinkedSortedType.h"
#include <stdexcept>

LinkedSortedType::LinkedSortedType()
{
    length = 0;
    listData = nullptr;
}

bool LinkedSortedType::isFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

int LinkedSortedType::getLength() const
{
    return length;
}

void LinkedSortedType::makeEmpty()
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

ItemType LinkedSortedType::getItem(ItemType item)
{
    bool moreToSearch;
    NodeType* location;

    location = listData;
    bool found = false;
    moreToSearch = (location != nullptr);

    while (moreToSearch && !found)
    {
        switch (item.comparedTo(location->info))
        {
            case 1:     location = location->next;
                        moreToSearch = (location != nullptr);
                        break;
            case 0:     found = true;
                        item = location->info;
                        break;
            case -1:    moreToSearch = false;
                        break;
        }
    }

    return item;
}

void LinkedSortedType::putItem(ItemType item)
{
    NodeType* newNode;  // pointer to the node being inserted
    NodeType* predLoc;  // trailing pointer
    NodeType* location; // traveling pointer
    bool moreToSearch;

    location = listData;
    predLoc = nullptr;
    moreToSearch = (location != nullptr);

    while (moreToSearch)
    {
        switch (item.comparedTo(location->info))
        {
            case 1:     predLoc = location;
                        location = location->next;
                        moreToSearch = (location != nullptr);
                        break;
            case -1:    moreToSearch = false;
                        break;
        }
    }

    // prepare node for insertion
    newNode = new NodeType;
    newNode->info = item;

    // insert node into list
    if (predLoc == nullptr)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }

    length++;
}

void LinkedSortedType::deleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;

    // locate node to be deleted
    if (item.comparedTo(location->info) == 0)
    {
        tempLocation = location;
        listData = listData->next; // delete first node
    }
    else
    {
        while (item.comparedTo((location->next)->info) != 0)
            location = location->next;

        // delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }

    delete tempLocation;
    length--;
}

void LinkedSortedType::resetList()
{
    currentPos = nullptr;
}

ItemType LinkedSortedType::getNextItem()
{
    ItemType item;
    if (currentPos == nullptr)
        currentPos = listData;
    item = currentPos->info;
    currentPos = currentPos-> next;
    return item;
}

LinkedSortedType::~LinkedSortedType()
{
    NodeType* tempPtr;

    while (listData != nullptr)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}