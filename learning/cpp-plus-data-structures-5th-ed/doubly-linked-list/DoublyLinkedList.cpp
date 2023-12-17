// cpp-plus-data-structures-5th-ed/doubly-linked-list/DoublyLinkedList.cpp

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType>* next;
    NodeType<ItemType>* back;
};

template <class ItemType>
void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, bool& found)
{
    bool moreToSearch = true;
    location = listData;
    found false;
    
    while (moreToSearch && !found)
    {
        if (item.compareTo(location->info) == LESS)
            moreToSearch = false;
        else if (item.compareTo(location->info) == EQUAL)
            found = true;
        else
        {
            location = location->next;
            moreToSearch = (location == nullptr);
        }
    }
}