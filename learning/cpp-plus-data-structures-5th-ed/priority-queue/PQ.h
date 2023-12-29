// learning/cpp-plus-data-structures-5th-ed/priority-queue/PQ.h

#include "heap/Heap.h"

class FullPQ
{

};

class EmptyPQ
{

};

template<class ItemType>
class PQType
{
    public:
        PQType(int);
        ~PQType();
        void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(ItemType item);
        void dequeue(ItemType item);
    private:
        int length;
        HeapType<ItemType> items;
        int maxItems;
};