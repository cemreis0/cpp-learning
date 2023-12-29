// learning/cpp-plus-data-structures-5th-ed/binary-search-trees/IterativeInsertionAndDeletion.cpp

#include "TreeType.h"
#include "TreeType.cpp"

// general function to find a node
template<class ItemType>
void findNode(TreeNode<ItemType>* tree, ItemType item, TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*& parentPtr)
/*
post: if a node is found with the same key as item's, then
nodePtr points to that node and parentPtr points to its
parent node. if the root node has the same key as item's,
parentPtr is nullptr. if no node has the same key, then
nodePtr is nullptr and parentPtr points to the node in the
tree that is the logical parent of item
*/
{
    nodePtr = tree;
    parentPtr = nullptr;
    bool found = false;

    while (nodePtr != nullptr && !found)
    {
        if (item < nodePtr->info)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->left;
        }
        else if (item > nodePtr->info)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->right;
        }
        else
        {
            found = true;
        }
    }
}

template<class ItemType>
void TreeType<ItemType>::putItem(ItemType item)
// post: item is in tree
{
    TreeNode* newNode;
    TreeNode* nodePtr;
    TreeNode* parentPtr;

    newNode = new TreeNode;
    newNode->info = item;
    newNode->left = nullptr;
    newNode->right = nullptr;

    findNode(root, item, nodePtr, parentPtr);

    if (parentPtr == nullptr)
        root = newNode; // insert as root
    else if (item < parentPtr->info)
        parentPtr->left = newNode;
    else
        parentPtr->right = newNode;
}

template<class ItemType>
void TreeType<ItemType>::deleteItem(ItemType item)
// post: there is no node in the tree that whose info member matches item
{
    TreeNode* nodePtr;
    TreeNode* parentPtr;

    findNode(root, item, nodePtr, parentPtr);

    if (nodePtr == root)
        removeNode(root);
    else
        if (parentPtr->left == nodePtr)
            removeNode(parentPtr->left);
        else
            removeNode(parentPtr->right);
}