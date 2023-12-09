// cpp-plus-data-structures-5th-ed/linked-stack/LinkedStackType.h

class FullStack
{

};

class EmptyStack
{
    
};

struct NodeType;

class LinkedStackType
{
    public:
        LinkedStackType();
        ~LinkedStackType();
        void push(char item);
        void pop();
        char getTop();
        bool isEmpty() const;
        bool isFull() const;
    private:
        NodeType* topPtr;
};

struct NodeType
{
    char info;
    NodeType* next;
};