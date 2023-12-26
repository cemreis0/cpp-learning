// learning/cpp-plus-data-structures-5th-ed/binary-search-trees/TreeType.cpp

#include "TreeType.h"

template<class ItemType>
TreeType<ItemType>::TreeType()
{
    root = nullptr;
}

template<class ItemType>
void destroy(TreeNode<ItemType>*& tree);
template<class ItemType>
TreeType<ItemType>::~TreeType()
// call the recursive function destroy to destroy the tree
{
    destroy(root);
}

template<class ItemType>
void copyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType& originalTree)
// call the recursive function copyTree to copy originalTree into root
{
    copyTree(root, originalTree.root);
}

template<class ItemType>
void TreeType<ItemType>::operator=(TreeType& originalTree)
// call the recursive function copyTree to copy originalTree into root
{
    if (&originalTree = this)
        return; // ignore assigning self to self
    destroy(root); // destroy existing nodes
    copyTree(root, originalTree.root);
}

template<class ItemType>
void TreeType<ItemType>::makeEmpty()
{
    destroy(root);
    root = nullptr;
}

template<class ItemType>
bool TreeType<ItemType>::isEmpty() const
// return true if the tree is empty,
// false otherwise
{
    return (root == nullptr);
}

template<class ItemType>
bool TreeType<ItemType>::isFull() const
// return true if the free store has no room,
// false otherwise
{
    TreeNode* location;
    try
    {
        location = new TreeNode;
        delete location;
        return false;
    }
    catch (std::bad_alloc e)
    {
        return true;
    }
}

template<class ItemType>
int countNodes(TreeNode<ItemType>* tree);
template<class ItemType>
int TreeType<ItemType>::getLength() const
// call the recursive function countNodes to count the nodes
// in the tree
{
    return countNodes(root);
}

template<class ItemType>
void retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);
template<class ItemType>
ItemType TreeType<ItemType>::getItem(ItemType item, bool& found)
// call the recursive function retrieve to search tree for the item
{
    retrieve(root, item, found);
    return item;
}

template<class ItemType>
void insert(TreeNode<ItemType>* tree, ItemType& item);
template<class ItemType>
void TreeType<ItemType>::putItem(ItemType item)
// call the recursive function insert to insert the item into the tree
{
    insert(root, item)
}

template<class ItemType>
void removeNode(TreeNode<ItemType>* tree);
template<class ItemType>
void remove(TreeNode<ItemType>* tree, ItemType& item);
template<class ItemType>
void TreeType<ItemType>::deleteItem(ItemType item)
// call the recurisve function remove to delete the item from the tree
{
    delete(root, item);
}

template<class ItemType>
void preOrder(TreeNode<ItemType>*, QueType&);
template<class ItemType>
void inOrder(TreeNode<ItemType>*, QueType&);
template<class ItemType>
void postOrder(TreeNode<ItemType>*, QueType&);
template<class ItemType>
void TreeType<ItemType>::resetTree(OrderType order)
// calls a function to create a queue of the tree elements in
// the desired order
{
    switch (order)
    {
        case PRE_ORDER:     preOrder(root, preQue); break;
        case IN_ORDER:      inOrder(root, inQue); break;
        case POST_ORDER:    postOrder(root, postOrder); break;
    }
}

template<class ItemType>
ItemType TreeType<ItemType>::getNextItem(OrderType order, bool& finished)
// return the next item in the desired order
// post:    for the desired order, item is the next item in the queue.
//          if item is the last one in the queue, finished is true;
//          otherwise, finished is false.
{
    ItemType item;
    finished = false;

    switch (order)
    {
        case PRE_ORDER:     preQue.dequeue(root, preQue); if (preQue.isEmpty()) finished = true; break;
        case IN_ORDER:      inQue.dequeue(root, inQue); if (inQue.isEmpty()) finished = true; break;
        case POST_ORDER:    postQue.dequeue(root, postOrder); if (postQue.isEmpty()) finished = true; break;
    }

    return item;
}

template<class ItemType>
void printTree(TreeNode<ItemType>* tree, std::ofstream& outFile);
template<class ItemType>
void TreeType<ItemType>::print(std::ofstream& outFile) const
{
    printTree(root, outFile);
}



// --------------------------------------------------------------



template<class ItemType>
int countNodes(TreeNode<ItemType>* tree)
// post: return the number of items in the tree
{
    if (tree = nullptr)
        return 0;
    else
        return countNodes(tree->left) + countNodes(tree->right) + 1;
}

template<class ItemType>
void retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
// function: recursively search the tree for the item
// post:    if there is an element whose key matches the item's
//          found is true and the item is set to a copy of element
//          otherwise, found is false and the item is unchanged
{
    if (tree = nullptr)
        found = false;
    else if (item < tree->info)
        retrieve(tree->left, item, found);
    else if (item > tree->info)
        retrieve(tree->right, item, found);
    else
    {
        item = tree->info;
        found = true;
    }
}

template<class ItemType>
void insert(TreeNode<ItemType>* tree, ItemType& item)
// function: insert the item into the thee
// post: the item is inserted into the tree, search property is maintained
{
    if (tree == nullptr)
    {
        tree = new TreeNode;
        tree->left = nullptr;
        tree->right = nullptr;
        tree->info = item;
    }
    else if (item < tree->info)
        insert(tree->left, item);
    else
        insert(tree->right, item);
}

template<class ItemType>
void remove(TreeNode<ItemType>* tree, ItemType& item)
// function: delete the item from the tree
// post: the item is not in the tree
{
    if (item < tree->info)
        remove(tree->left, item);
    else if (item > tree->info)
        remove(tree->right, item);
    else
        removeNode(tree);
}

template<class ItemType>
void getPredecessor(TreeNode<ItemType>* tree, ItemType& data);
template<class ItemType>
void removeNode(TreeNode<ItemType>* tree, ItemType& item)
// function: delete the node pointed to by tree
// post:    the user's data in the node pointed to by tree is no
//          longer in the tree. if the tree is a leaf node or has only
//          one non-null child pointer, the node pointed to by tree is
//          deleted; otherwise, the user's data is replaced by its
//          logical predecessor and the predecessor's node is deleted
{
    ItemType data;
    TreeNode<ItemType>* tempPtr;

    tempPtr = tree;

    if (tree->left == nullptr)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == nullptr)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(tree->left, data);
        tree->info = data;
        remove(tree->left, data);
    }
}

template<class ItemType>
void getPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// function: set data to the info member of the rightmost node in the tree
{
    while (tree->right != nullptr)
        tree = tree->right;
    data = tree->info;
}

template<class ItemType>
void printTree(TreeNode<ItemType>* tree, std::ofstream& outFile)
// function: print info member of items in the tree in sorted order on outFile
{
    if (tree != nullptr)
    {
        printTree(tree->left, outFile);
        outFile << tree->info;
        printTree(tree->right, outFile);
    }
}

template<class ItemType>
void destroy(TreeNode<ItemType>*& tree)
// post: the tree is empty, nodes have been deallocated
{
    if (tree != nullptr)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

template<class ItemType>
int copyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree)
// post: copy is the root of a tree that is a duplicate of originalTree
{
    if (originalTree == nullptr)
        copy = nullptr;
    else
    {
        copy = new TreeNode;
        copy->info = originalTree->info;
        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}

template<class ItemType>
void preOrder(TreeNode<ItemType>* tree, QueType& preQue)
// post: preQue contains the three items in pre-order
{
    if (tree != nullptr)
    {
        preQue.enqueue(tree->info);
        preOrder(tree->left, preQue);
        preOrder(tree->right, preQue);
    }
}

template<class ItemType>
void inOrder(TreeNode<ItemType>* tree, QueType& preQue)
// post: inQue contains the three items in in-order
{
    if (tree != nullptr)
    {
        preOrder(tree->left, preQue);
        preQue.enqueue(tree->info);
        preOrder(tree->right, preQue);
    }
}

template<class ItemType>
void postOrder(TreeNode<ItemType>* tree, QueType& preQue)
// post: postQue contains the three items in post-order
{
    if (tree != nullptr)
    {
        preOrder(tree->left, preQue);
        preOrder(tree->right, preQue);
        preQue.enqueue(tree->info);
    }
}