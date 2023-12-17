// cpp-plus-data-structures-5th-ed/circular-linked-list/CircularLinkedList.cpp

template<class ItemType>

void findItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found)
{
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;

    while (moreToSearch && !found)
    {
        if (item.compareTo(location->info) == -1)
            moreToSearch = false;
        else if (item.compareTo(location->info) == 0)
            found = true;
        else
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template<class ItemType>
void putItem(ItemType item)
{
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;

    if ((listData->info.compareTo(item)) == -1)
    {
        findItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;

        // if this is the last node in the list, reassign listData
        if (listData->info.compareTo(item) == -1)
            listData = newNode;
    }
    else // insert into an empty list
    {
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template<class ItemType>
void deleteItem(ItemType item)
{
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    bool found;

    findItem(listData, item, location, predLoc, found);
    if (predLoc == location) // only node in the list?
        listData = nullptr;
    else
    {
        predLoc->next = location->next;
        if (location == listData) // deleting the last node in the list?
            listData = predLoc;
    }
    delete location;
    length--;
}