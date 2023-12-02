// cpp-plus-data-structures-5th-ed/linked-sorted-list/LinkedSortedType.h

#include "ItemType.h"
struct NodeType;

class LinkedSortedType
{
    public:
        LinkedSortedType();
        ~LinkedSortedType();
        bool isFull() const;
        int getLength() const;
        void makeEmpty();
        ItemType getItem(ItemType item);
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