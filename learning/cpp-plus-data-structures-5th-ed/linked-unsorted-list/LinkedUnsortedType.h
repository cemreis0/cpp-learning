// cpp-plus-data-structures-5th-ed/linked-unsorted-list/LinkedUnsortedType.h

#include "ItemType.h"

struct NodeType;

class LinkedUnsortedType
{
    public:
        LinkedUnsortedType();
        void makeEmpty();
        bool isFull() const;
        int getLength();
        ItemType getItem(ItemType item, bool &found);
        void putItem(ItemType item);
        void deleteItem(ItemType item);
        void resetList();
        ItemType getNextItem();
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
};

struct NodeType
{
    ItemType info;
    NodeType* next;
};