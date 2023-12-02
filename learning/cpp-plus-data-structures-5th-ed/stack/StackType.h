// cpp-plus-data-structures-5th-ed/stack/StackType.h

#pragma once

class FullStack
{

};

class EmptyStack
{
    
};

class StackType
{
    public:
        StackType();
        bool isEmpty() const;
        bool isFull() const;
        void push(char item);
        void pop();
        char getTop() const;
    private:
        static const int MAX_ITEMS = 5;
        int top;
        char items[MAX_ITEMS];
};