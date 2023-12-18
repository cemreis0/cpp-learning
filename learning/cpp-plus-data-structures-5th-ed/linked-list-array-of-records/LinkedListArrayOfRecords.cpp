// learning/cpp-plus-data-structures-5th-ed/linked-list-array-of-records/LinkedListArrayOfRecords.cpp

struct MemoryType;

class ListType
{
    public:
        // member function prototypes
    private:
        int listData;
        int currentPos;
        int length;
        int maxItems;
        MemoryType storage;
};

// the following code defines MemoryType and implements auxiliary functions

// prototypes of auxiliary functions
void getNode(int& nodeIndex, MemoryType& storage); // return the index of a free node in nodeIndex
void freeNode(int nodeIndex, MemoryType& storage);  // return the nodeIndex to storage
void initializeMemory(int maxItems, MemoryType&); // initialize all memory to the free list

// define end-of-list symbol
const int NUL = -1;

struct NodeType
{
    int info;
    int next;
};

struct MemoryType
{
    int free;
    NodeType* nodes;
};

void initializeMemory(int maxItems, MemoryType& storage)
{
    for (int i = 1; i < maxItems; i++)
        storage.nodes[i-1].next = i;
    storage.nodes[maxItems-1].info = NUL;
    storage.free = 0;
}

void getNode(int& nodeIndex, MemoryType& storage)
{
    nodeIndex = storage.free;
    storage.free = storage.nodes[storage.free].next;
}

void freeNode(int nodeIndex, MemoryType& storage)
{
    storage.nodes[nodeIndex].next = storage.free;
    storage.free = nodeIndex;
}
