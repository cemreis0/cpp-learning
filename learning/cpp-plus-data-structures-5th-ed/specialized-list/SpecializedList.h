// learning/cpp-plus-data-structures-5th-ed/specialized-list/SpecializedList.cpp

struct NodeType;

class SpecializedList
{
    public:
        SpecializedList();
        ~SpecializedList();
        SpecializedList(const SpecializedList& list); // copy constructor

        // initialize current position for an iteration through
        // the list from first item to last item
        void resetForward();

        // get the next item in the structure
        // finished is true if all items have been accessed
        void getNextItem(int& item, bool& finished);

        // initialize current position for an iteration through
        // the list from last item to first item
        void resetBackward();

        // get the previous item in the structure
        // finished is true if all items have been accessed
        void getPriorItem(int& item, bool& finished);

        // insert item as the first item in the structure
        void putFront(int item);

        // insert item as the last item in the structure
        void putEnd(int item);

        // return the number of items in the structure
        int getLength();
    private:
        NodeType* list;
        NodeType* currentNextPos;
        NodeType* currentBackPos;
        int length;
};

struct NodeType
{
    NodeType* next;
    NodeType* back;
    int info;
};