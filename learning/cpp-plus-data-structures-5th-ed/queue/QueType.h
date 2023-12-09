// cpp-plus-data-structures-5th-ed/queue/QueType.h

#pragma once

class FullQueue
{

};

class EmptyQueue
{

};

class QueType
{
    public:
        QueType(int max);
        ~QueType();
        void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        void enqueue(int item);
        void dequeue(int& item);
    private:
        int front;
        int rear;
        int* items;
        int maxQue;
};