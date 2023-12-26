// learning/cpp-plus-data-structures-5th-ed/binary-search-trees/TreeType.h

#pragma once

#include <iostream>
#include "queue/QueType.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template<class ItemType>
class TreeType
{
    public:
        TreeType();
        ~TreeType();
        TreeType(const TreeType& originalTree);
        void operator=(TreeType& originalTree);
        void makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
        int getLength() const;
        ItemType getItem(ItemType item, bool& found);
        void putItem(ItemType item);
        void deleteItem(ItemType item);
        void resetTree(OrderType order);
        ItemType getNextItem(OrderType order, bool& finished);
        void print(std::ofstream& outFile) const;
    private:
        TreeNode* root;
        QueType preQue;
        QueType inQue;
        QueType postQue;
};

template<class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};