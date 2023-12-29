// learning/cpp-plus-data-structures-5th-ed/heap/Heap.cpp

template<class ItemType>
struct HeapType
{
    void reheapDown(int root, int bottom);
    void reheapUp(int root, int bottom);
    ItemType* elements; // array to be allocated dynamically
    int numElements;
};