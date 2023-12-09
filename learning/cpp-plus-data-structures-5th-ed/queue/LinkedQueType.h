// cpp-plus-data-structures-5th-ed/queue/LinkedQueType.h

#pragma once

class FullQueue
{

};

class EmptyQueue
{

};

struct NodeType;

class LinkedQueType
{
    public:
        LinkedQueType();
        ~LinkedQueType();
        void makeEmpty();
        void enqueue(int item);
        void dequeue(int& item);
        bool isEmpty() const;
        bool isFull() const;
    private:
        NodeType* front;
        NodeType* rear;
};

struct NodeType
{
    int info;
    NodeType* next;
};